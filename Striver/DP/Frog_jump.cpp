#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int a=0;
    int b=abs(heights[n-2]-heights[n-1]);

    int curr=-1;
    for(int i=n-3;i>=0;i--){
        curr=min(abs(heights[i+1]-heights[i])+b,abs(heights[i+2]-heights[i])+a);
        a=b;
        b=curr;
    }
    return curr;
}