#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define PORT 8080
#define BUFFER_SIZE 1024

const unsigned char FLAG = 0x7E;
const unsigned char ESC = 0x7D;

// Byte unstuffing function
string byteUnstuffing(const string& data) {
    string unstuffed;
    bool inFrame = false;

    for (size_t i = 0; i < data.size(); ++i) {
        unsigned char ch = data[i];

        if (ch == FLAG) {
            if (!inFrame) {
                inFrame = true;
                continue; // Skip start FLAG
            } else {
                break; // End of frame
            }
        }

        if (ch == ESC && i + 1 < data.size()) {
            i++;
            if (data[i] == 0x5E) unstuffed += FLAG;
            else if (data[i] == 0x5D) unstuffed += ESC;
        } else {
            unstuffed += ch;
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

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 1;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) return 1;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, 3) == SOCKET_ERROR) {
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Waiting for sender..." << endl;
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrlen);
    if (clientSocket == INVALID_SOCKET) {
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    string received(buffer);
    cout << "Received Stuffed Message: " << received << endl;

    string original = byteUnstuffing(received);
    cout << "Unstuffed Message (Original): " << original << endl;

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
