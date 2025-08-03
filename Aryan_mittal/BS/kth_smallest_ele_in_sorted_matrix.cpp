// 1st solution using priority queue max heap
// we only maintained k elements in the queue..
// at the end , the ele at the top will be the kth smallest ele



// 2nd solution using binary search on ans(BS normal is not possible as we can't determine as how many ele are smaller than ith index if we r currently on ith index)

class Solution {
    public:
        int count_of_smaller_ele(vector<vector<int>> &matrix,int mid,int n){
            int count=0;
            for(int i=0;i<n;i++){
               count+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin()); // binary serach to determine number of ele smaller than or equal to the value mid...
            }
            return count;
        }
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            // using the kth charcteristic only....
    
            // priority_queue<int> pq;
            // int n=matrix.size();
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         pq.push(matrix[i][j]);
            //         if(pq.size()>k) pq.pop();
            //     }
            // }
            // return pq.top();
    
            //given sorted word so we can use binary search also.....
            
            int n=matrix.size();
            int l=matrix[0][0];
            int h=matrix[n-1][n-1];
            int ans=-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                int count=count_of_smaller_ele(matrix,mid,n);
                if(count>=k){
                    ans=mid;
                    h=mid-1;
                }
                
                else l=mid+1;
            }
            return ans;
        }
    };