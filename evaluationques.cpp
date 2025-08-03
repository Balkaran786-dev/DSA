#include<iostream>
#include<vector>
using namespace std;
int superDigit(int num){
    if(num%10==num){
        return num;
    }
    else{
    int ans;
    int lastdigit;
    int sum=0;
    while(num!=0){
        lastdigit=num%10;
        sum+=lastdigit;
        num/=10;
    }
    ans=sum;
    superDigit(ans);
    }
}
int main(){
   vector<int> num;
   num.push_back(8);
   cout<<num.size();
}