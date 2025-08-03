/*
if you r creating too many variants of a samefunction just 
to pass variables of different datatypes,then instaed
of making so many functions,you can  pass template variable 
in that one function,then you can pass any vairiable of your choice.
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template<class T1, class T2>
float funcAverage(T1 a, T2 b){
    float avg= (a+b)/2.0; 
    return avg;
}
int main(){
    float a;
    a = funcAverage<int,int>(5,2);
    printf("The average of these numbers is %f",a);

    int x=90,y=89;
    swapp<int>(x,y);
    cout<<x<<" "<<y;
    return 0;
}

