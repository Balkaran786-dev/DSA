//approach1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
     

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] * prefix[i - 1];
        }

       
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i] * suffix[i + 1];
        }

        
        vector<int> ans(n);
        ans[0] = suffix[1];
        ans[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = prefix[i - 1] * suffix[i + 1];
        }

        return ans;
    }
};


//APPROACH 2
//first multiply every element in anwer with prefixProduct till just before it- means now ans[i] is multiplied with all before elements,
//then multiply every element in answer with suffixProduct till just after it(iterate from last) and now ans[i] is multiplied with all afterwards elements. and we got our required answer
//tc-n, sc-1
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int prefProd=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=prefProd;
            prefProd*=nums[i];
        }

        int suffProd=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=suffProd;
            suffProd*=nums[i];
        }
        return ans;
    }