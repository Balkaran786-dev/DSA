#include<iostream>
using namespace std;
int main(){         //hamesha right to left dekhna hai during increment and decrement, unless and untill there is parenthesis present
    int x=90;
    float y=3.4;
    double z=8.45;
    cout<<sizeof(x)<<" "<<sizeof(y)<<" "<<sizeof(z)<<endl;

    int *ptr=&x;
    double *ptrd=&z;
    cout<<ptr+1<<" "<<ptr+4<<endl;
    cout<<ptrd<<" "<<ptrd+1;

   int array1[]={1,19};
   int  *ptr=&array1[0];
   cout<<*ptr++<<endl;  //yahan address me ek increment ho raha hai..
   cout<<*ptr<<endl;    // kyunki post increment tha isliye abh increase ho gya..
   
   int array2[]={5,4};
   int *ptr2=&array2[0];
   cout<<(*ptr2)++<<endl;  // yahan jo value uss address pe ha usme ek add hoga..
   cout<<(*ptr2)++<<endl;
   cout<<array2[0];
   
   int array3[]={6,9};
   int *ptr3=&array3[0];
   cout<<++*ptr3<<endl;  // derefrence operator pehle value dega fer usme increment hoga..
   cout<<*++ptr3<<endl; //isme address mein increment hoga fer dereference operator use hoga..
                 
   
   int ar[]={19,6};
   int *ptr=ar;
   cout<<++*ptr;  // it will change the first element of ar array
   cout<<ar[0]<<" "<<ar[1];
    return 0;
}