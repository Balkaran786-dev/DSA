// stop_and_wait_server.cpp
#include <winsock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    int clientLen = sizeof(client);

    char buffer[BUFFER_SIZE];
    int sequenceNumber = 0;

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Prepare server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));

    // Listen
    listen(serverSocket, 3);

    std::cout << "Waiting for client...\n";
    clientSocket = accept(serverSocket, (struct sockaddr*)&client, &clientLen);
    std::cout << "Client connected.\n";

    while (true) {
        std::string message;
        std::cout << "Enter message to send (type 'exit' to quit): ";
        std::getline(std::cin, message);

        if (message == "exit") break;

        // Add sequence number
        message = std::to_string(sequenceNumber) + ":" + message;

        send(clientSocket, message.c_str(), message.length(), 0);

        // Wait for ACK
        memset(buffer, 0, BUFFER_SIZE);
        recv(clientSocket, buffer, BUFFER_SIZE, 0);

        std::string ack(buffer);
        if (ack == "ACK" + std::to_string(sequenceNumber)) {
            std::cout << "Received ACK for frame " << sequenceNumber << "\n";
            sequenceNumber = 1 - sequenceNumber; // Toggle between 0 and 1
        } else {
            std::cout << "ACK not received. Resending...\n";
        }
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
