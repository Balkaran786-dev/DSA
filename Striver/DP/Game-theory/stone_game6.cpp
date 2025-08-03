class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        return v1[0]>v2[0]; 
    }
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<vector<int>> stones(n,vector<int> (3));
        for(int i=0;i<n;i++){
            int total=aliceValues[i]+bobValues[i];
            stones[i][0]=total;
            stones[i][1]=aliceValues[i];
            stones[i][2]=bobValues[i];
        }

        sort(stones.begin(),stones.end(),cmp);
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
               a+=stones[i][1];
            }
            else b+=stones[i][2];
        }

        if(a==b) return 0;
        else if(a>b) return 1;
        return -1;
    }
};