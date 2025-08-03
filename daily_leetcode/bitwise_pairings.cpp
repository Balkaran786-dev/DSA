//2425.
// solely based on observation.

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        
        if((n1 & 1)==0 && (n2 & 1)==0){
            return 0;
        }
        else if((n1 & 1) && (n2 & 1)){
            int ans=0;
            for(int i=0;i<n1;i++){
                ans^=nums1[i];
            }
            for(int i=0;i<n2;i++){
                ans^=nums2[i];
            }
            return ans;
        }
        else if((n1 & 1)==0){
            int ans=0;
            for(int i=0;i<n1;i++){
                ans^=nums1[i];
            }
            return ans;
        }
            int ans=0;
            for(int i=0;i<n2;i++){
                ans^=nums2[i];
            }
            return ans;
    }
};