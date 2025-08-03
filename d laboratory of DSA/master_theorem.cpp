#include<bits/stdc++.h>
using namespace std;

float solve( int x, int k){
   float answer;
   answer = log10( x ) / log10( k );
   return answer;
}
void Time_complexity(float a,float b,float k,float p){
    if(a>pow(b,k)){
        float temp=solve(a,b);
        cout<<"O(n^"<<temp<<")";
    }
    else if(a==pow(b,k)){
        float temp=solve(a,b);
        if(p>-1){
           cout<<"Theta(n^"<<temp<<"(logn)^"<<p+1;
        }
        else if(p==-1){
            cout<<"Theta(n^"<<temp<<"(loglogn)";
        }
        else if(p<-1){
            cout<<"Theta(n^"<<temp<<")";
        }
    }
    else if(a<pow(b,k)){
        if(p>0){
            cout<<"Theta(n^"<<k<<"(logn)^"<<p;
        }
        else{
            cout<<"Theta(n^"<<k<<")";
        }
    }
}
int main(){
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";   
    cout<<"Expression: T(n)=aT(n/b)+O(n^(k) (logn)^p"<<endl;
    float a,b,k,p;
    cout<<"Enter value of a>=1: ";
    cin>>a;
    cout<<"Enter value of b>1: ";
    cin>>b;
    cout<<"Enter value of k>=0: ";
    cin>>k;
    cout<<"Enter value of p as a real number: ";
    cin>>p;
    
   
    Time_complexity(a,b,k,p);
    return 0;
}
