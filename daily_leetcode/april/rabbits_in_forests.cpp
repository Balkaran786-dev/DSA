class Solution {
    public:
        int numRabbits(vector<int>& v) {
            int n=v.size();
            sort(v.begin(),v.end());
            int cnt=0;
            int i=0;
            while(i<n){
                int value=v[i];
                int j=i+1;
                while(j<n && v[i]==v[j]){
                    j++;
                }
                int len=j-i;
                int a=ceil((len*1.0)/(value+1));
                cnt+=(a*(value+1));
                i=j;
            }
            return cnt;
        }
    };