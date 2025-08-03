#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

using namespace std;

// Function to calculate Longitudinal Redundancy Check (LRC)
int lrc(const vector<int>& data) {
    int lrc_bit = 0;
    for (int bit : data) {
        lrc_bit ^= bit; // XOR all bits
    }
    return lrc_bit;
}

int main() {
    int choice;

    while (true) {
        cout << "\nMenu-driven Error Detection Technique: Longitudinal Redundancy Check (LRC)\n";
        cout << "1. Calculate LRC\n";
        cout << "2. Exit\n";
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

                int lrc_value = lrc(data);
                cout << "LRC value: " << lrc_value << endl;
                break;
            }

            case 2:
                cout << "Exiting program..." << endl;
                return 0; // Exit the program

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
