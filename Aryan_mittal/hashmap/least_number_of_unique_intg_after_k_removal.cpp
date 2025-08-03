// space efficient
class Solution {
    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            int n=arr.size();
            unordered_map<int,int> mp;
    
            for(int i=0;i<n;i++){
                mp[arr[i]]++;
            }
            
    
            while(k>0){
               int smallest_freq=INT_MAX;
               pair<int,int> req;
               for(auto ele:mp){
                   if(smallest_freq>ele.second){
                       smallest_freq=ele.second;
                       req=ele;
                   }
               }
               
               if(req.second>k){
                return mp.size();
               }
               else{
                   k-=req.second;
                   mp.erase(req.first);
               }
            }
    
            return mp.size();
            
        }
};

 // time efficient
class Solution {
    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            int n=arr.size();
            unordered_map<int,int> mp;
    
            for(int i=0;i<n;i++){
                mp[arr[i]]++;
            }
            
            int sz=mp.size();
            vector<int> freq(sz);
            int i=0;
            for(auto ele:mp){
                freq[i++]=ele.second;
            }
    
            sort(freq.begin(),freq.end());
    
            for(int i=0;i<sz;i++){
                if(freq[i]>k){
                    return sz-i;
                }
                
                k-=freq[i];
                
            }
            return 0;
        }
    };