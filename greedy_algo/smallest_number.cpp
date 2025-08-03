#include<iostream>
#include<vector>
using namespace std;
string smallest_no(int d,int s){
  string res="";
  if(9*d>=s){
    vector<char> v(d,'0');
    int i;
    for(i=d-1;i>=0;i--){
        if(s<=9){
            if(i!=0){
                break;
            }
            else if(i==0){
                v[i]=char(s+'0');
            }
        }
        else if(s>9){
            v[i]='9';
            s-=9;
        }
    }
    if(i!=-1){
        v[i--]=char((s-1)+'0');
        while(i!=0){
            v[i]='0';
            i--;
        }
        v[i]='1';
    }

    for(i=0;i<=d-1;i++){
        res+=v[i];
    }
  }
  else{
    res+="NP";
  }
    return res;
}
int main(){
    int d,s;
    cin>>d>>s;
    cout<<smallest_no(d,s);
    return 0;
}



class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(9*d<s){
            return "-1";
        }
        
        vector<int> ans(d,0);
        if(s>=1){  //kya pta sum zero hi ho. tooh case mein 1st digit ko 1 nhi bnayenge
            ans[0]=1;
            s--;
        }
    
        if(s!=0){
            for(int i=d-1;i>=0;i--){ 
                if(s+ans[i]>9){ 
                    ans[i]=9;
                    s-=ans[i];
                }
                else{
                    ans[i]+=s;
                    s=0;
                }
            }
        }
        
        string num="";
        for(int i=0;i<d;i++){
            num+=(ans[i]+'0');
        }
        return num;
    }
};
