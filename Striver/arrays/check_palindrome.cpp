class Solution {
public:
    bool f(int temp,int &num){
     if(temp>0 && temp<=9){
        int last_dig=num%10;
        num/=10;
        return last_dig==temp;
     }
    
     bool res=f(temp/10,num);
     if(res==false) return false;
     else{
        int last_dig=num%10;
        num/=10;
        return last_dig==temp%10;
     }
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        return f(x,x);
    }
};