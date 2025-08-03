// use of heaps..
class Solution {
    public:
        long long totalCost(vector<int>& costs, int k, int candidates) {
            int n=costs.size();
            if(candidates*2>=n){
                priority_queue<int,vector<int>,greater<int>> pq;
                for(int i=0;i<n;i++){
                    pq.push(costs[i]);
                }
                long long cost=0;
                while(k--){
                    cost+=pq.top();
                    pq.pop();
                }
    
                return cost;
            }
            
                priority_queue<int,vector<int>,greater<int>> left;
                priority_queue<int,vector<int>,greater<int>> right;
                long long cost=0;
                int left_ptr= candidates-1;
                int right_ptr= n-candidates;
    
                for(int i=0;i<candidates;i++){
                    left.push(costs[i]);
                }
                for(int i=n-1;i>=n-candidates;i--){
                    right.push(costs[i]);
                }
    
                while(k--){
                    if(!left.empty() && (right.empty() || left.top() <= right.top())){
                        cost+=left.top();
                        left.pop();
                        if (left_ptr + 1 < right_ptr) {  // Ensure they don’t overlap
                          left_ptr++;
                          left.push(costs[left_ptr]);
                        }
                    }
                    else{
                        cost+=right.top();
                        right.pop();
                        if (right_ptr - 1 > left_ptr) {  // Ensure they don’t overlap
                          right_ptr--;
                          right.push(costs[right_ptr]);
                        }
                    }
                }
                return cost;
            
        }
    };