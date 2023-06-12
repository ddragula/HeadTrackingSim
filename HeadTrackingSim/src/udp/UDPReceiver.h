#pragma once
#include <iostream>
#include <asio.hpp>
#include <array>
#include <cstring>
#include <algorithm>
#include <glm/glm.hpp>

class UDPReceiver
{
public:
	UDPReceiver(int port);
	glm::vec3 receivePositionVector();
private:
	static UDPReceiver* instance;
	asio::io_context ioContext;
	asio::ip::udp::socket* socket;
	std::array<char, sizeof(float) * 3> receiveBuffer;
};

