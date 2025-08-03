#include <iostream>
#include <stdlib.h>
using namespace std;

class Sample {
public:
    int B;
    static int A;
    Sample()
    {
        B = 10;
        A++;
    }
};
int Sample::A = 0;

int main()
{
    Sample S1, S2;
    new Sample();  //it is returning a pointer

    cout << (new Sample())->B << " ";
    cout << Sample::A;

    return 0;
}