#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the number of parity bits required
int calculateParityBits(int dataBits) {
int parityBits = 0;
while (pow(2, parityBits) < (dataBits + parityBits + 1)) {
parityBits++;
}
return parityBits;
}

// Function to encode the data using Hamming Code
vector<int> encodeHammingCode(const vector<int>& data) {
int dataBits = data.size();
int parityBits = calculateParityBits(dataBits);
int totalBits = dataBits + parityBits;

vector<int> hammingCode(totalBits, 0);

int j = 0;
// Place data bits in their correct positions
for (int i = 0; i < totalBits; i++) {
if ((i + 1) & i) {
// If position is a power of 2, skip it for data bits
continue;
}
hammingCode[i] = data[j++];
}

// Calculate parity bits
for (int i = 0; i < parityBits; i++) {
int parityPos = pow(2, i) - 1;
int parity = 0;
for (int j = parityPos; j < totalBits; j += 2 * (parityPos + 1)) {
for (int k = j; k < j + parityPos + 1 && k < totalBits; k++) {
parity ^= hammingCode[k];
}
}
hammingCode[parityPos] = parity;
}
return hammingCode;
}

// Function to detect and correct errors using Hamming Code
void detectAndCorrectHammingCode(vector<int>& received) {
int totalBits = received.size();
int parityBits = calculateParityBits(totalBits - 1);

int errorPos = 0;

// Check parity bits and calculate the error position
for (int i = 0; i < parityBits; i++) {
int parityPos = pow(2, i) - 1;
int parity = 0;

for (int j = parityPos; j < totalBits; j += 2 * (parityPos + 1)) {
for (int k = j; k < j + parityPos + 1 && k < totalBits; k++) {
parity ^= received[k];
}
}

if (parity != 0) {
errorPos += (parityPos + 1);
}
}

if (errorPos != 0) {
cout << "Error detected at position: " << errorPos << endl;
// Correct the error
received[errorPos - 1] ^= 1;
} else {
cout << "No error detected." << endl;
}

cout << "Corrected Hamming Code: ";
for (int i = 0; i < received.size(); i++) {
cout << received[i];
}
cout << endl;
}

int main() {
int choice;

while (true) {
cout << "Menu-driven Error Detection Technique: Hamming Code\n";
cout << "1. Encode data using Hamming Code\n";
cout << "2. Detect and correct errors using Hamming Code\n";
cout << "3. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1: {
int n;
cout << "Enter the number of data bits: ";
cin >> n;
vector<int> data(n);

cout << "Enter the data bits (0 or 1): ";
for (int i = 0; i < n; i++) {
cin >> data[i];
}

// Encode the data using Hamming Code
vector<int> encoded = encodeHammingCode(data);

cout << "Encoded Hamming Code: ";
for (int i = 0; i < encoded.size(); i++) {
cout << encoded[i];
}
cout << endl;
break;
}
case 2: {
int n;
cout << "Enter the number of total bits (data + parity): ";
cin >> n;
vector<int> received(n);

cout << "Enter the received bits (0 or 1): ";
for (int i = 0; i < n; i++) {
cin >> received[i];
}

// Detect and correct errors using Hamming Code
detectAndCorrectHammingCode(received);
break;
}
case 3:
cout << "Exiting program..." << endl;
return 0;
default:
cout << "Invalid choice. Please try again.\n";
}
}

return 0;
}
