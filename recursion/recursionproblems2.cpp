// #include<iostream>  
// using namespace std;   //finding gcd through recursion
// int gcd(int a,int b){  //a>b
//     if(b>a) return gcd(b,a);
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<gcd(a,b);
// }



#include<iostream>
using namespace std; //finding gcd through iteration
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a,b;
    cin>>a>>b;
    if(a<b){
        swap(&a,&b);
    }
    while(b!=0){
        a%=b;
        swap(&a,&b);
    }
     cout<<a;
     return 0;
}

// #include<iostream>
// #include<math.h>
// using namespace std;
// int f(int n,int d){
//     if(n==0){
//         return 0;
//     }
//     return pow((n%10),d)+f(n/10,d);
// }
// int main(){
//     int n;
//     cin>>n;
//     int num=n;
//     int no_of_digits=0;
//     while(num!=0){
//       no_of_digits+=1;
//       num/=10;
//     }
//     int result=f(n,no_of_digits);
//     if(n==result){
//         cout<<"ARMSTRONG";
//     }
//     else{
//         cout<<"NOT ARMSTRONG";
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int f(int h[],int i,int n){
//     if(i==n-1) return 0;
//     if(i==n-2) return f(h,i+1,n)+abs(h[i]-h[i+1]);

//     return min(f(h,i+1,n)+abs(h[i]-h[i+1]),f(h,i+2,n)+abs(h[i]-h[i+2]));
// }
// int main(){
//     int n;
//     cin>>n;
//     int h[n];
//     for(int i=0;i<n;i++){
//         cin>>h[i];
//     }
//     cout<<f(h,0,n);
//     return 0;
// }

