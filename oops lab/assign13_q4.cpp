#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    
    // Open a file to write student data
    ofstream outFile("students.txt");

    string name;
    int rollNumber;
    for (int i = 0; i < numStudents;i++) {
        
        cout << "Enter name of student " << (i + 1) << ": ";
        cin>>name;
        cout << "Enter roll number of student " << (i + 1) << ": ";
        cin >> rollNumber;
        outFile << name << " " << rollNumber << endl;
    }

    // Close the output file
    outFile.close();

    // Open the file for reading
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    // Display the content of the file
    cout << "\nContents of the file:\n";
    while (inFile >> name >> rollNumber) {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }

    // Close the input file
    inFile.close();

    return 0;
}
