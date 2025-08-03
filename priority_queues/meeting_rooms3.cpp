class Solution {
public:
    using pp=pair<long long,int>;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int sz=meetings.size();
        map<int,int> held;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(int i=0;i<n;i++){
             pq.push({0,i});
             held[i]=0;
        }
        for(int i=0;i<sz;i++){
            pp curr=pq.top();
            pq.pop();
            if(curr.first>=meetings[i][0]){
                held[curr.second]++;
                pq.push({1LL*meetings[i][1]-meetings[i][0]+curr.first,curr.second});
            }
            else{
                pq.push({meetings[i][0],curr.second});
                i--;
            }
        }
        int maxi=INT_MIN;
        int ans=-1;
        for(auto ele:held){
            if(maxi<ele.second){
                ans=ele.first;
                maxi=ele.second;
            }
        }
        return ans;
    }
};