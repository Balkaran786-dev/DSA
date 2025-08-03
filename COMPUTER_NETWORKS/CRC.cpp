#include <iostream>
#include <vector>
using namespace std;

vector<int> performCRC(const vector<int>& data, const vector<int>& divisor) {
    vector<int> temp = data;
    int n = data.size(), m = divisor.size();

    for (int i = 0; i <= n - m; i++) {
        if (temp[i] == 1) {
            for (int j = 0; j < m; j++) {
                temp[i + j] ^= divisor[j];
            }
        }
    }

    return vector<int>(temp.end() - (m - 1), temp.end());
}

vector<int> calculateCRC(const vector<int>& data, const vector<int>& divisor) {
    vector<int> extendedData = data;
    extendedData.insert(extendedData.end(), divisor.size() - 1, 0);
    return performCRC(extendedData, divisor);
}

int main() {
    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            int n, m;
            cout << "data size";
            cin >> n;
            vector<int> data(n);
            cout << "data";
            for (int i = 0; i < n; i++) cin >> data[i];

            cout << "divisor size";
            cin >> m;
            vector<int> divisor(m);
            cout << "divisor ";
            for (int i = 0; i < m; i++) cin >> divisor[i];

            vector<int> crc = calculateCRC(data, divisor);
            cout << "CRC Checksum: ";
            for (int bit : crc) cout << bit;
            cout << endl;
        } 
        else if (choice == 2) {
            cout << "Exit\n";
            break;
        } 
        else {
            cout << "Invalid";
        }
    }
    return 0;
}
