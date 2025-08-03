#include <bits/stdc++.h>
using namespace std;

// Function to compute checksum
string compute_checksum(string data, int block_size) {
    int n = data.length();
    int sum = 0;
    
    for (int i = 0; i < n; i += block_size) {
        int block = stoi(data.substr(i, block_size), nullptr, 2);
        sum += block;
        if (sum > 255) {  // Handle overflow by wrapping around
            sum = (sum & 255) + (sum >> 8);
        }
    }
    sum = ~sum & 255;  // Ensure it's within 8 bits
    return bitset<8>(sum).to_string();
}

// Checksum validation
bool validate_checksum(string received_data, int block_size) {
    string received_checksum = received_data.substr(received_data.length() - 8);
    string original_data = received_data.substr(0, received_data.length() - 8);
    string computed_checksum = compute_checksum(original_data, block_size);
    return computed_checksum == received_checksum;
}

// Checksum function
void checksum(string data, int block_size) {
    if (data.length() % block_size != 0) {
        cout << "Error: Data length is not a multiple of block size." << endl;
        return;
    }
    string checksum_value = compute_checksum(data, block_size);
    cout << "Checksum: " << checksum_value << endl;
    cout << "Transmitted Data: " << data + checksum_value << endl;
    if(validate_checksum(data + checksum_value , 8)){
        cout<<"Recieved data is validated by the reciever"<<endl;
        return;
    }
    cout<<"Recieved data is not valid"<<endl;
}



// Function to compute LRC (Longitudinal Redundancy Check)
string compute_LRC(string data, int block_size) {
    if (data.length() % block_size != 0) {
        cout << "Error: Data length is not a multiple of block size." << endl;
        return "";
    }
    string LRC(block_size, '0');
    for (int i = 0; i < data.length(); i += block_size) {
        for (int j = 0; j < block_size; j++) {
            LRC[j] = (LRC[j] == data[i + j]) ? '0' : '1';
        }
    }
    return LRC;
}


// LRC validation
bool validate_LRC(string received_data, int block_size) {
    string received_LRC = received_data.substr(received_data.length() - block_size);
    string original_data = received_data.substr(0, received_data.length() - block_size);
    string computed_LRC = compute_LRC(original_data, block_size);
    return computed_LRC == received_LRC;
}

// LRC function
void LRC(string data, int block_size) {
    string lrc = compute_LRC(data, block_size);
    if (lrc.empty()) return;
    cout << "LRC: " << lrc << endl;
    cout << "Transmitted Data: " << data + lrc << endl;
    if(validate_LRC(data + lrc , 8)){
        cout<<"Recieved data is validated by the reciever"<<endl;
        return;
    }
    cout<<"Recieved data is not valid"<<endl;
}

int main() {
    int choice;
    cout << "Choose the method you want to implement: " << endl;
    cout << "1. Checksum" << endl;
    cout << "2. LRC" << endl;
    cout << "3. CRC" << endl;
    cout << "4. Hamming Code" << endl;
    cin >> choice;

    string data;
    cout << "Enter your binary data: ";
    cin >> data;

    if (data.empty()) {
        cout << "Error: Input data cannot be empty." << endl;
        return 1;
    }

    switch (choice) {
        case 1:
            checksum(data, 8);
            break;
        case 2:
            LRC(data, 8);
            break;
        
        default:
            cout << "Invalid input";
            break;
    }
    return 0;
}