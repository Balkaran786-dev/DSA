class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    
        vector<vector<int>> vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                vector<int> temp(3);
                temp[0]=i+j;
                temp[1]=i;
                temp[2]=nums[i][j];
                vec.push_back(temp);
            }
        }

        sort(vec.begin(),vec.end(),cmp);
        int sz=vec.size();
        vector<int> ans(sz);
        for(int i=0;i<sz;i++){
            ans[i]=vec[i][2];
        }
        return ans;
    }
};