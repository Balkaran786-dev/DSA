class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
            int n_satisfy=0,a_satisfy=0;
            int n=customers.size();
            for(int i=0;i<k;i++){
               if(grumpy[i]==0) n_satisfy+=customers[i];
               else a_satisfy+=customers[i];
            }
    
            int count=a_satisfy;
            for(int i=k;i<n;i++){
                 if(grumpy[i-k]==1) a_satisfy-=customers[i-k];
                 if(grumpy[i]==0) n_satisfy+=customers[i];
                 else{
                    a_satisfy+=customers[i];
                 }
                 count=max(count,a_satisfy);
            }
            return count + n_satisfy;
        }
    };