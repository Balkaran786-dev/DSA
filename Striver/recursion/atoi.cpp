//iterative one  // my approach
class Solution {
public:
    long convert_to_int(long ans,int val,int mul){
           return ans*mul+val;
    }
    int myAtoi(string s) {
        bool started=false;
        bool sign=true; //positive
        int n=s.size();
        long ans=0;
        int mul=10;

        for(int i=0;i<n;i++){
              if(s[i]==' '){  
                if(!started){
                    continue;
                }
                else{
                    break;
                }
              }
              else if(s[i]=='-'){
                if(!started){
                    sign=false;  //marking the ans as -ve
                    started=true;  //if we once see -ve, we will start our integer from it.hence marking the started as true, because if we get any whitespace or + or - ,we will return 0;
                }
                else{
                    break;
                }
              }
              else if(s[i]<48 || s[i]>57){
                if(s[i]=='+'){
                    if(!started){
                        started=true; //start hogya intg
                        continue;
                    }
                    else{  
                        break;
                    }
                }
                break;
              }
              else{  //integer
                 started=true;
                 int val=s[i]-48;
                 ans=convert_to_int(ans,val,mul);
                 if(ans>=pow(2,31) && !sign) return INT_MIN;
                 else if(ans>=pow(2,31)) return INT_MAX;
              }
        }
        if(!sign) return -1*ans;
        return ans;
    }
};

