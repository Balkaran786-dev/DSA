#include <bits/stdc++.h> 
bool isArmstrong(int num) {
    // Write your code here
    int check=10;
    int i=1;
    int digits=-1;
    while(check<=pow(10,9)){
            if(num<check){
                digits=i;
                break;
            }
            if(num==check){
                digits=i+1;
                break;
            }
            i+=1;
            check*=10;
    }

    int sum=0;
    int p=num;
    while(num!=0){
        int parity=num%10;
        sum+=pow(parity,digits);
        num/=10;
    }
    if(sum==p) return true;
    return false;
}