class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        //2 means live hai per baad mein dead hojayega
        //3 means dead hai per baad mein live hojayega

        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
               int live=0;
               int dead=0;
               for(int d=0;d<8;d++){
                int n_x=i+dir[d][0];
                int n_y=j+dir[d][1];
                if(n_x<0 || n_y<0 || n_x>=n || n_y>=m) continue;

                if(board[n_x][n_y]==2 || board[n_x][n_y]==1) live++;
                else dead++;
               }

               int curr_state=board[i][j];
               if(curr_state==1 && (live<2 || live>3)) board[i][j]=2;
               else if(curr_state==0 && (live==3)) board[i][j]=3;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==3) board[i][j]=1;
            }
        }
        return;
    }
};