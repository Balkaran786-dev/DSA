//first solu  o(n^2) time o(1) space
//generating all substring
// when forming substring , will include only 2 type of ele if third ele comes, ill break out of inner loop,means ill stop my subtring 

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mp;
        int l=0,r=0;
        int length=0;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            
            if(mp.size()<=2){
                length=max(length,r-l+1);
            }
            r++;
        }
        
        return length;
    }
};