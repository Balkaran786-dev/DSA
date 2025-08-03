//explained in copy
class Solution {
    public:
        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
            int n=quality.size();
            vector<pair<double,int>> vec(n);
            
            for(int i=0;i<n;i++){
                vec[i]={wage[i]*1.0/quality[i],quality[i]};
            }
            sort(vec.begin(),vec.end());
            priority_queue<int> pq;
            int sum=0;
            double min_amount=DBL_MAX;
            for(int i=0;i<n;i++){
                 double ratio=vec[i].first;
                 pq.push(vec[i].second);
                 sum+=vec[i].second;
                 if(pq.size()>k){
                    sum-=pq.top();
                     pq.pop();
                 }
                 if(pq.size()==k) min_amount=min(min_amount,sum*ratio);
            }
            return min_amount;
        }
    };