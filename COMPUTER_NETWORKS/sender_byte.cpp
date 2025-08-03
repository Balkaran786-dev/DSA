#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define PORT 8080
#define SERVER_IP "127.0.0.1"

const unsigned char FLAG = 0x7E;
const unsigned char ESC = 0x7D;

// Byte stuffing function
string byteStuffing(const string& data) {
    string stuffed;
    stuffed += FLAG; // Start flag

    for (unsigned char ch : data) {
        if (ch == FLAG) {
            stuffed += ESC;
            stuffed += 0x5E;
        } else if (ch == ESC) {
            stuffed += ESC;
            stuffed += 0x5D;
        } else {
            stuffed += ch;
        }
    }

    stuffed += FLAG; // End flag
    return stuffed;
}

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 1;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) return 1;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    string message;
    cout << "Enter message to send: ";
    getline(cin, message); // accept normal ASCII input

    string stuffedMessage = byteStuffing(message);
    send(clientSocket, stuffedMessage.c_str(), stuffedMessage.length(), 0);
    cout << "Byte-stuffed message sent!" << endl;

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
