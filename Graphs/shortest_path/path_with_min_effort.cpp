//yaahn humne visited kyu nhi liye and endNode milne pe return kyu nhi kiya??
//here hume at the end hi jab sara ways se uss node tak pahunch jaye tabb hi ans mil payega.
//beacuse it can be possible that pehle path se uss endNode tak ka effort jada , aye baad mein kam aye,



//we can also use a simple queue, but it will take more time. and can put the same node in queue multiple times..

//why pq prefereable, beause isme hum, nodes ka distance update tabhi krte hain and queue ke andr dalte hain,
//jab hume voh purane vale se better mile,.


class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    using pp = pair<int,pair<int,int>>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>> distance(m,vector<int> (n,INT_MAX));
        distance[0][0]=0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            pp curr=pq.top();
            pq.pop();
            int dist=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            if(i==m-1 && j==n-1) continue;
            for(int d=0;d<4;d++){
                int row=dir[d][0]+i;
                int col=dir[d][1]+j;
                
                if(row<0 || col<0 || row>=m || col>=n ) continue;
                int effort=max(dist,abs(heights[row][col]-heights[i][j]));
                if(effort>=distance[row][col]) continue;
                distance[row][col]=effort;
                pq.push({effort,{row,col}});
            }
        }
        return distance[m-1][n-1];
    }
};