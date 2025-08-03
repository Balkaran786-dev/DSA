//explanation given in copy..
#include <bits/stdc++.h> 
int maxXor(int L, int R)
{
    // Write your code here.
    int x=L^R;
    if(x==0) return 0;
    int i=-1;
    for(i=31;i>=0;i--){
        if(x & (1<<i)){
            break;
        }
    }

    return (1<<(i+1))-1;
}

