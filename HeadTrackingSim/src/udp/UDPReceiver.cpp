#include "UDPReceiver.h"

float reverseBytes(float value) {
	std::array<unsigned char, sizeof(float)> bytes;
	std::memcpy(bytes.data(), &value, sizeof(float));
	std::reverse(bytes.begin(), bytes.end());
	float result;
	std::memcpy(&result, bytes.data(), sizeof(float));
	return result;
}

UDPReceiver::UDPReceiver(int port) {
	socket = new asio::ip::udp::socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), port));
}

glm::vec3 UDPReceiver::receivePositionVector()
{
	asio::ip::udp::endpoint senderEndpoint;

	std::size_t bytesReceived = socket->receive_from(asio::buffer(receiveBuffer), senderEndpoint);

	if (bytesReceived == (sizeof(float) * 3)) {
		float floatData[3];
		std::memcpy(floatData, receiveBuffer.data(), sizeof(float) * 3);

		for (int i = 0; i < 3; ++i) {
			floatData[i] = reverseBytes(floatData[i]);
		}

		return glm::vec3(floatData[0], floatData[1], floatData[2]);
	}
}
