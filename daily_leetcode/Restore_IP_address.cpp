class Solution {
public:
    void get_Addresses(string &s, int start,int n,int dots,vector<string> &ans,vector<string> temp){
          if(dots==4 && start<n){
            string part=s.substr(start);
            int sz=part.size();
            if((part[0]=='0' && part.size()>1) || sz>3) return;  //1st condition handle if there is like 078,05 in last part after 3rd dot
                                                                 // 2nd condition handles if size of the part is already greater than 3 , obviously not gonna be a valid adress.
            if(stoi(part)<=255){
                temp.push_back(part);
                ans.push_back(temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3]);
            }
            return; //dono hi cases mein return toh krna hi hai, chahe part >255 ho ya nhi.
          }
          
          if(s[start]=='0'){  // this condition is tackled before to get rid of leading zeroes.
            string part="0";
            temp.push_back(part);
            get_Addresses(s,start+1,n,dots+1,ans,temp);
            temp.pop_back();
            return;
          }

          for(int i=start;i<n;i++){
            string part=s.substr(start,i-start+1);
            if(stoi(part)<=255){
                temp.push_back(part);
                get_Addresses(s,i+1,n,dots+1,ans,temp);
                temp.pop_back();
            }
            else{
                return;
            }
          }

    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string> ans;
        vector<string> temp;
        int start=0;
        int dots=1;
        get_Addresses(s,start,n,dots,ans,temp);
        return ans;
    }
};