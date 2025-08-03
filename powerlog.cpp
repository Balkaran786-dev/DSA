// #include<iostream>
// using namespace std;
// int powerlog(int a,int b){
//     if(b==0){             // finding  a^b 
//         return 1;
//     }
//     int x=powerlog(a,b/2);
//     if(b%2==0){
//         return x*x;
//     }
//     else{
//         return x*x*a;
//     }
// }
// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<powerlog(a,b);
// }


// #include<iostream>
// using namespace std;
// int fibo(int n){
//     if(n==1||n==2){   //fibonacci series
//         return 1;
//     }
//     return fibo(n-1)+fibo(n-2);
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<fibo(n);
//     return 0;
// }

#include<iostream>
using namespace std;   // only one and two steps are allowed
int stairpath(int n){
     if(n==1 || n==2){
        return n;
     }
     return stairpath(n-1)+stairpath(n-2);
}
int main(){
    int n;  // number of stairs
    cin>>n;
    cout<<stairpath(n);
    return 0;
}



// #include<iostream>
// using namespace std;   // only one, two and three steps are allowed
// int stairpath(int n){
//      if(n==1||n==2){
//         return n;
//      }
//      if(n==3){
//         return 4;
//      }
//      return stairpath(n-1)+stairpath(n-2)+stairpath(n-3);
// }
// int main(){
//     int n;  // number of stairs
//     cin>>n;
//     cout<<stairpath(n);
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int mazepath(int n,int m){
//     if(n==1 || m==1){
//         return 1;
//     }
//     return mazepath(n-1,m)+mazepath(n,m-1);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     cout<<mazepath(n,m);
//     return 0;
// }

// #include<iostream>
// using namespace std;
// void preinpost(int n){
//     if(n==0){
//         return;
//     }
//     cout<<n;
//     preinpost(n-1);
//     cout<<n;
//     preinpost(n-1);
//     cout<<n;
// }
// int main(){
//     int n;
//     cin>>n;
//     preinpost(n);
//     return 0;
// }