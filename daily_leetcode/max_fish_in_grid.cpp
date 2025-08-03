// har ek connected component mein kitni fish kha skte hain, voh calculate krlo..
// and ek max_count mein rkhte jayo..

class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int findMaxFish(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        int max_count=0;
        queue<pair<int,int>> qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if(graph[i][j]!=0){
                int cnt=0;
                qu.push(make_pair(i,j));
                while(!qu.empty()){
                        auto pair=qu.front();
                        int first=pair.first;
                        int second=pair.second;
                        cnt+=graph[first][second];
                        graph[first][second]=0;  //trapped the fish
                        qu.pop();
                        for(int i=0;i<4;i++){
                            int new_Row=first+dir[i][0];
                            int new_Col=second+dir[i][1];
                            if(new_Row>=0 && new_Row<n && new_Col>=0 && new_Col<m){
                                if(graph[new_Row][new_Col]!=0){
                                    qu.push(make_pair(new_Row,new_Col));
                                }
                            }
                        }
                }
                max_count=max(max_count,cnt);
            }
        }
    }
    return max_count;
    }
};