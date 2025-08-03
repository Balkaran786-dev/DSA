// stop_and_wait_client.cpp
#include <winsock2.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET clientSocket;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int expectedSequence = 0;

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Setup server address
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    connect(clientSocket, (struct sockaddr*)&server, sizeof(server));
    std::cout << "Connected to server.\n";

    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int recvLen = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (recvLen <= 0) break;

        std::string received(buffer);
        int seq = received[0] - '0'; // Get sequence number
        std::string data = received.substr(2);

        std::cout << "Received frame: " << data << " [Seq: " << seq << "]\n";

        if (seq == expectedSequence) {
            std::string ack = "ACK" + std::to_string(seq);
            send(clientSocket, ack.c_str(), ack.length(), 0);
            expectedSequence = 1 - expectedSequence;
        } else {
            std::cout << "Duplicate frame. Resending previous ACK.\n";
            std::string ack = "ACK" + std::to_string(1 - expectedSequence);
            send(clientSocket, ack.c_str(), ack.length(), 0);
        }
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
