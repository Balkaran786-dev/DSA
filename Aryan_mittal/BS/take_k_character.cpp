class Solution {
    public:
        bool func(string &s,int mid,int k,int n){
            int a=0,b=0,c=0;
            for(int i=0;i<mid;i++){
                if(s[i]=='a')a++;
                else if(s[i]=='b')b++;
                else c++;
            }
            if(a>=k && b>=k && c>=k) return true;
            
            int j=n-1;
            for(int i=mid-1;i>=0;i--){
                if(s[i]=='a')a--;
                else if(s[i]=='b')b--;
                else c--;
    
                if(s[j]=='a')a++;
                else if(s[j]=='b')b++;
                else c++;
                if(a>=k && b>=k && c>=k) return true;
                j--;
            }
            return false;
        }
        int takeCharacters(string s, int k) {
            int n=s.size();
            int l=k*3;
            int h=n;
            if(h<l) return -1;
            int ans=-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(func(s,mid,k,n)){
                    h=mid-1;
                    ans=mid;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
    };
