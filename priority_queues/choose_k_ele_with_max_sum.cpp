// using maxheap
// giving TLE, for some last testcases
// o(nlogn + n*k);


#define pp pair<int,int>
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long> ans(n);
        vector<vector<int>> vec(n,vector<int> (2));

        for(int i=0;i<n;i++){
            vec[i][0]=nums1[i];
            vec[i][1]=i;
        }

        priority_queue<pp> pq;
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            int ele=vec[i][0];
            if(pq.empty()){
                ans[vec[i][1]]=0;
                pq.push({nums2[vec[i][1]],ele});
                continue;
            }
            vector<pp> temp;
            long long to_put=0;
            int k1=k;
            while(!pq.empty()){
                pp p1=pq.top();
                temp.push_back(p1);
                pq.pop();
                if(k1>0 && p1.second<ele){
                    to_put+=p1.first;
                    k1--;
                }
                if(k1==0) break;
            }
            ans[vec[i][1]]=to_put;
            for(auto ele:temp){
                pq.push(ele);
            }
            pq.push({nums2[vec[i][1]],ele});
        }
        return ans;
    }
};

// using minheap  //o(nlogn + n )
// minheap because im maintaing max to max k ele in heaps
// if size becomes greater, i need to remove the smallest possible ele so that the ele
// inside makes the largest sum possible.
// also, at every index, im not going to take out ele and sum them up and then put them back
// rather ill maintain a sum of all of the ele presnt in the heap,
// whenever, ill insert some ele in heap, ill add it to sum, and when i remove some ele, ill reduce it from sum
// edge case:-
// what if , nums1[i-1]==nums1[i], so, ill keep the previous ans to this index also,


class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
             ios_base::sync_with_stdio(0);
                cin.tie(0);
                cout.tie(0);
    
            int n = nums1.size();
            vector<long long>ans(n);
            vector<array<int,3>>v;
            for(int i = 0; i < n; i++)
                v.push_back({nums1[i],nums2[i],i});
            sort(v.begin(),v.end());
            for(auto it:v)
                cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            priority_queue<int, vector<int>, greater<int>>pq; //min heap so we can maintain larger sum in pq and top element always has the smallest num2 value
            long long curr_sum = 0;
            for(int i = 0;i < n;i++){
                if(i && v[i - 1][0] == v[i][0])
                    ans[v[i][2]] = ans[v[i - 1][2]];
                else
                    ans[v[i][2]] = curr_sum;
                curr_sum += v[i][1];
                pq.push(v[i][1]);
    
                if(pq.size() > k){
                    curr_sum -= pq.top(); 
                    pq.pop(); //removing the smaller element from pq.
                }
            }
            return ans;
        }
    };