#include<iostream>
using namespace std;
int fibonacci(int n){
    int array[n+1];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
       array[i]=array[i-1]+array[i-2];
    }
    return array[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);
}

      //in first approach,space is growing as we change the n;
      //in second,space remains the same i.e three variables.
      //although,the time complexity is same in both.  O(n)


#include<iostream>
using namespace std;
int fibonacci(int n){
   int a=0,b=1,c=1;   //c gives us the nth term
   for(int i=2;i<=n;i++){
    c=a+b;
    a=b;
    b=c;
   }
   return c;
}
int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);
}

