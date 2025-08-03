//simple queue beacuse edge weight is only 1...



class Solution {
  public:
    int MOD = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n=arr.size();
        int steps=0;
        queue<int> qu;
        vector<int> visited(100000,-1);
        qu.push(start);
        while(!qu.empty()){
            int sz=qu.size();
            while(sz--){
                int curr=qu.front();
                qu.pop();

                if(curr==end) return steps;
                for(int i=0;i<n;i++){
                    int val=(curr*arr[i])%MOD;
                    if(visited[val]==-1){
                        visited[val]=1;
                        qu.push(val);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};