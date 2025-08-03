#include <iostream>
using namespace std;

void autoStorageClass()
{
    cout << "Demonstrating auto storage class\n";

    // Declaring auto storage class variables
    int a = 32;
    float b = 3.2f;
    char *c = "GeeksforGeeks";
    char d = 'G';

    // Printing the auto storage class variables
    cout << a << " \n";
    cout << b << " \n";
    cout << c << " \n";
    cout << d << " \n";
}

int main()
{
    // To demonstrate auto Storage Class
    autoStorageClass();

    return 0;
}