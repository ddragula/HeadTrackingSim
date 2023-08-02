#include <iostream>
#include <asio.hpp>
#include "App.h"

float reverseBytes(float value) {
    std::array<unsigned char, sizeof(float)> bytes;
    std::memcpy(bytes.data(), &value, sizeof(float));
    std::reverse(bytes.begin(), bytes.end());
    float result;
    std::memcpy(&result, bytes.data(), sizeof(float));
    return result;
}

void asyncFunction(App* app) {
    asio::io_context ioContext;
    asio::ip::udp::socket socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), 8080));

    std::array<char, sizeof(float) * 3> receiveBuffer;

    while (app->isRunning()) {
        asio::ip::udp::endpoint senderEndpoint;

        std::size_t bytesReceived = socket.receive_from(asio::buffer(receiveBuffer), senderEndpoint);

        if (bytesReceived == (sizeof(float) * 3)) {
            float floatData[3];
            std::memcpy(floatData, receiveBuffer.data(), sizeof(float) * 3);

            for (int i = 0; i < 3; ++i) {
                app->udpVector[i] = reverseBytes(floatData[i]);
            }
        }
    }
}

int main()
{
    const auto app = App::create();
    std::future<void> futureResult = std::async(std::launch::async, asyncFunction, app);
    app->loop();
    App::terminate();
    return 0;
}
