#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")  // Link with Winsock library

using namespace std;

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to perform bit unstuffing
string bitUnstuffing(string stuffed) {
    string unstuffed = "";
    int count = 0;

    for (size_t i = 0; i < stuffed.length(); i++) {
        unstuffed += stuffed[i];

        if (stuffed[i] == '1') {
            count++;
            if (count == 5 && i + 1 < stuffed.length() && stuffed[i + 1] == '0') {
                i++;  // Skip the stuffed '0'
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return unstuffed;
}

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrlen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE] = {0};

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed!" << endl;
        return 1;
    }

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed!" << endl;
        WSACleanup();
        return 1;
    }

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Bind failed!" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for connections
    if (listen(serverSocket, 3) == SOCKET_ERROR) {
        cerr << "Listen failed!" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Waiting for sender..." << endl;

    // Accept client connection
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrlen);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Accept failed!" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Receive message
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    cout << "Received Stuffed Message: " << buffer << endl;

    // Perform bit unstuffing
    string receivedMessage = bitUnstuffing(buffer);
    cout << "Unstuffed Message (Original Data): " << receivedMessage << endl;

    // Close sockets
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
