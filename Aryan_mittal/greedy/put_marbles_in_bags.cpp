// main thing is you only cared about the border ele of every group
// since, the first and last ele are always going to be the part  of group , so they will participate both in min and max score
// we need to care about the k-1 partitions that we need to do in between.
// when we did those k-1 partitions, the side by ele are going to be added anyway in the score,
// we can make a vector of these sums of side by side ele, and then 
// sort it and then for max score, take the k-1 from behind
// and for min score, take k-1 from ahead..
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n=weights.size();
            vector<long long> partitions(n-1);
            for(int i=0;i<n-1;i++){
                partitions[i]=1LL*weights[i]+weights[i+1];
            }
    
            sort(partitions.begin(),partitions.end());
            long long max_score=0,min_score=0;
            for(int i=0;i<=k-2;i++){
                min_score+=partitions[i];
            }
            
            for(int i=n-2;i>=n-k;i--){
                max_score+=partitions[i];
            }
    
            return max_score-min_score;
    
        }
    };