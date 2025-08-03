#include<iostream>
using namespace std;
int sumOfDigits(int n){  //this function basically gives us the sum of all digits of n
    if(n>=0 && n<=9){
        return n;
    }
    return n%10+sumOfDigits(n/10); //hum last digit ko add krdenge aap baki ki digits ka sum le aye.
}
int main(){
    int num;
    cin>>num;
    int result=sumOfDigits(num);
    cout<<result;
    return 0;
}

int power(int p,int q){
   
    if(q==0){
        return 1;
    }
    return p*power(p,q-1);
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    int result=power(n1,n2);
    cout<<result;
    return 0;
}

  //More optimised recursive solution..
int power(int p,int q){ //it gives p^q
    if(q==0){
        return 1;
    }
    if(q==1){
        return p;
    }
    if(q%2==0){
        int ans=power(p,q/2); //aap p^q/2 le aye 
        return ans*ans;  //hum p^q/2 * p^q/2=p^q bna lenge.
    }
    else{
        int ans=power(p,q-1/2); //aap p^q-1/2 le aye 
        return p*ans*ans;  //hum p * p^q-1/2 * p^q-1/2=p^q bna lenge.
    }
}
int main(){
    int p,q;
    cin>>p>>q;
    cout<<power(p,q);
    return 0;
}