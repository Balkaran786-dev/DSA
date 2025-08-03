#include<iostream>  //gcd or hcf: the greatest number that divides both the number completely.
using namespace std;
int main(){
    int a,b; 
    cin>>a>>b;
    int hcf;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            hcf=i;
        }
    }
    cout<<hcf;
}


//LCM:the least number that is the multiple of one number and is divisible by another number.

#include<iostream>
using namespace std;
int lcm(int n,int m){  
    int i=1;
   while(true){
    if((n*i)%m==0){
      return n*i;
    }
    else{
        i++;
    }
   }
   return-1;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<lcm(n,m);
    return 0;
}

//GCD/HCF
#include<iostream>
using namespace std;
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