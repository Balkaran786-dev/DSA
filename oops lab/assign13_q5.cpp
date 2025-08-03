#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    string sourceFile, destinationFile;
    cout << "Enter the name of the source file: ";
    cin >> sourceFile;
    cout << "Enter the name of the destination file: ";
    cin >> destinationFile;

    ifstream inFile(sourceFile);
    if (!inFile) {
        cerr << "Error: Could not open source file for reading!" << endl;
        return 1;
    }

    ofstream outFile(destinationFile, ios::app);
   
    string line;
    int lineNumber = 1;

    ifstream destFileRead(destinationFile);
    while (getline(destFileRead, line)) {
        lineNumber++;
    }
    
    destFileRead.close();

    
    while (getline(inFile, line)) {
        outFile << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    
    inFile.close();
    outFile.close();

    cout << "Contents of the source file have been appended to the destination file with line numbers." << endl;

    return 0;
}
