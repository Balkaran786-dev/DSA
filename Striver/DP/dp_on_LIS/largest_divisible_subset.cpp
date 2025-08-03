class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& arr) {
            sort(arr.begin(),arr.end());
            // sort kyu kiya??
            // beacuse for example , if(b%a == 0 ) and b%c==0  
            //then if(a<b) then its for sure c%a==0, for ex a=3 b=9 c=18, 
            // but if we don't sort them it can not be alwyas true,  ex a=6 b=3 c=9 
            // although a%b==0 and c%b==0 but c%a!=0...hence sorting ensures that 
            //yeh case hum include na kr paye, and hume agr b mil gya that is 
            //dividing c fully , than a bhi surely krta hoga

            
            int n=arr.size();
            vector<int> backtrack(n);  //to trace back the LIS
        for(int i=0;i<n;i++){
            backtrack[i]=i;  //first of all, all index will have the starting of LIS from them selves only...
        }
          
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            int maxi=0;
            int idx=-1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(maxi<dp[j]){
                        maxi=dp[j];
                        idx=j;
                    }
                }
            }
            if(maxi!=0){
                dp[i]+=maxi;
                backtrack[i]=idx;
            }
        }
        
        int maxi=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(maxi<dp[i]){
                maxi=dp[i];
                idx=i;
            }
        }
    
        vector<int> ans(maxi);
        for(int i=maxi-1;i>=0;i--){
            ans[i]=arr[idx];
            idx=backtrack[idx];
        }
    
        return ans;
 