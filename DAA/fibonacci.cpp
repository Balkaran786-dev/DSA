/*
 this is TOP DOWN approach,in which we are heading downward till we reach the base case
 and when we start moving upward, we keep storing our values.
 Usually,this is done in recursion
*/

/*
In Bottom up approach,we just start from the bottom most element and then move upwards
we must know the ordering.
usually,applied in iterative approach.
*/ 

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;  //Global vector 
 //kind of like ek storage manager sa hai jisme hum state ki values store krke rakhenge and agar
 //hume dobara vahi state ki value use krni hogi,we will not recompute it.instead,we 
 //get its value from the vector.

int ftd(int n){   //space-o(n)..
    if(n==1 || n==0){
        return n;
    }
    else if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=ftd(n-1)+ftd(n-2);
    return dp[n];
}



int fbu(int n){  //space-o(n)
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}



int fbuo(int n){   //o(1)-space
    int a=0,b=1;
    int c;
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
    dp.resize(n+1,-1);  //jitni jada badi fibonacci value find krni hogi,utni jada badi hum dp vector bnayenge.
    cout<<ftd(n)<<" "<<fbu(n)<<" "<<fbuo(n);
    return 0;
}


//if dp[i]==-1 that means ith state of the problem has not been computed.