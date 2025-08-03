#include<iostream>
using namespace std;

int fact(int &n){ //this gives us the factorial of n
    //base case
    if(n==1){
        return 1;
    }
    int ans=fact(n-1)*n; //app n-1 ka factorial le aye hum usme n multiply kardenge.
    return ans;
}
int main(){
    int num;
    cin>>num;
    cout<<fact(num);
}

// int fibonacci(int n){ //basically this function is giving us the nth fibonacci number 
//     if(n==0){
//      return 0;
//     }
//     if(n==1){
//      return 1;
//     }
//     return fibonacci(n-1)+fibonacci(n-2); //aap n-1 and n-2 fibonacci number le aye hum unn dono ko add karke nth fibonacci find krlenge.
// }
// int main(){
//     int n;
//     cin>>n;
//     int result=fibonacci(n);
//     cout<<result;

//     return 0;
// }
