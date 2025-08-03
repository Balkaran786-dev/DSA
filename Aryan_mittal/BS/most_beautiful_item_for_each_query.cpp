// think of a case when the ele you have found has lesser beauty than the prices that are even smaller than it..
// in that case, you can maintain the prefix max in items only...

class Solution {
    public:
        int get_smaller(vector<vector<int>> &items,int value,int n){
            int ans=-1;
            int lo=0;
            int hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(items[mid][0]<=value){
                    ans=mid;
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            return ans;
        }
        vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            int n=items.size();
            sort(items.begin(),items.end());
    
            int maxi=1;
            for(int i=0;i<n;i++){
                  maxi=max(items[i][1],maxi);
                  items[i][1]=maxi;
            }
            
            int sz=queries.size();
            vector<int> ans(sz);
            for(int i=0;i<sz;i++){
                int value=queries[i];
                int idx=get_smaller(items,value,n);
                if(idx==-1){
                    ans[i]=0;
                }
                else{
                    ans[i]=items[idx][1];
                }
            }
            return ans;
        }
    };