//simply finding all possible combinations...
/// o(k+k) time
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int max_sum=0;
        int left_sum=0;
        for(int i=0;i<=k-1;i++){
            left_sum+=cardPoints[i];
        }
        max_sum=left_sum;
        int right_sum=0;
        int right_idx=n-1;
        for(int i=k-1;i>=0;i--){
            left_sum=left_sum-cardPoints[i];
            right_sum+=cardPoints[right_idx];
            max_sum=max(max_sum,left_sum+right_sum);
            right_idx--;
        }
        return max_sum;
    }
};