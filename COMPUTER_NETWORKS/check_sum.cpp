#include <iostream>
#include <vector>

using namespace std;

// Function for Checksum Calculation
int checksum(vector<int> data) {
int sum = 0;

// Sum all the bits in the data
for (int i = 0; i < data.size(); i++) {
sum += data[i];
}

// Return checksum value (sum % 256 for 8-bit checksum)
return sum % 256;
}

int main() {
int choice;

while (true) {
cout << "Menu-driven Error Detection Technique: Checksum\n";
cout << "1. Calculate Checksum\n";
cout << "2. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1: {
// Checksum calculation
int n;
cout << "Enter the number of data bits: ";
cin >> n;
vector<int> data(n);

cout << "Enter the data bits (0 or 1): ";
for (int i = 0; i < n; i++) {
cin >> data[i];
}

// Calculate checksum
int checksumValue = checksum(data);
cout << "Checksum value: " << checksumValue << endl;
break;
}
case 2:
cout << "Exiting program..." << endl;
return 0;
default:
cout << "Invalid choice. Please try again.\n";
}
}

return 0;
}
