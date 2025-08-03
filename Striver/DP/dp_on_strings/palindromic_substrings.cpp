class Solution {
    public:
        int solve(int i,string s,int j,int n){
                    int ans=(i+1==j?0:1);
                    while(i>=0 && j<n && s[i]==s[j]){
                          ans+=1;
                          i--;
                          j++;
                    }
                    return ans;
        }
        int countSubstrings(string s) {
                   int n=s.size();
                    // expand from the middle..
                    int cnt=0;
                    for(int i=0;i<n;i++){
                        int odd=solve(i-1,s,i+1,n);
                        int even=solve(i,s,i+1,n);
                        cout<<odd<<" "<<even<<endl;
                        cnt+=(odd+even);
                    }
            
                    return cnt;
        }
    };




    class Solution {
        public:
            bool solve(int &l,int &r,string &s,int n){
                while(l>=0 && r<n && s[l]==s[r]){
                    l--;
                    r++;
                }
                if(l<0 || r>=n) return true;
                return false;
            }
            string shortestPalindrome(string s) {
                int n=s.size();
                int start=(n%2==0? (n/2)-1 : n/2);
                for(int i=start;i>=0;i--){
                    int l=i; 
                    int r=i+1;
                    bool even=solve(l,r,s,n);
                    if(l<0 && r>=n) return s;
                    if(l<0){
                        string str=s.substr(r);
                        reverse(str.begin(),str.end());
                        return str+s;
                    }
                    l=i;
                    r=i;
                    bool odd=solve(l,r,s,n);
                    if(l<0 && r>=n) return s;
                    if(l<0){
                        string str=s.substr(r);
                        reverse(str.begin(),str.end());
                        return str+s;
                    }
                }
                return "";
            }
        };