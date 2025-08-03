#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")  // Link with Winsock library

using namespace std;

#define PORT 8080
#define SERVER_IP "127.0.0.1"

// Function to perform bit stuffing
string bitStuffing(string data) {
    string stuffed = "";
    int count = 0;

    for (char bit : data) {
        stuffed += bit;

        if (bit == '1') {
            count++;
            if (count == 5) {
                stuffed += '0'; // Stuff a '0' after five consecutive '1's
                count = 0; // Reset count
            }
        } else {
            count = 0;
        }
    }
    return stuffed;
}

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed!" << endl;
        return 1;
    }

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed!" << endl;
        WSACleanup();
        return 1;
    }

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Connection Failed!" << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Get message from user
    string message;
    cout << "Enter binary message to send: ";
    cin >> message;

    // Perform bit stuffing
    string stuffedMessage = bitStuffing(message);
    cout << "Stuffed Message (Sent): " << stuffedMessage << endl;

    // Send stuffed message
    send(clientSocket, stuffedMessage.c_str(), stuffedMessage.length(), 0);
    cout << "Message sent!" << endl;

    // Close socket
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
