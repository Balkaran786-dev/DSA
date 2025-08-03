//space effieceint
class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> qu;
    void bfs(vector<vector<char>>& board){
        while(!qu.empty()){
            auto ele=qu.front();
            qu.pop();
            int row=ele.first;
            int col=ele.second;
            for(int d=0;d<4;d++){
               int new_Row=row+dir[d][0];
               int new_Col=col+dir[d][1];
               if(new_Row<0 || new_Col<0 || new_Row>=board.size() || new_Col>=board[0].size()) continue;
               if(board[new_Row][new_Col]=='1' || board[new_Row][new_Col]=='X') continue;
               qu.push({new_Row,new_Col});
               board[new_Row][new_Col]='1';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                qu.push({i,0});
                board[i][0]='1';
            }
            if(board[0].size()>1){
               if(board[i][board[0].size()-1]=='O'){
                qu.push({i,board[0].size()-1});
                board[i][board[0].size()-1]='1'; 
              }
            }
            
        }
        if(board[0].size()>1){
              for(int j=1;j<=board[0].size()-2;j++){
                if(board[0][j]=='O'){
                  qu.push({0,j});
                  board[0][j]='1';
                }
                if(board[board.size()-1][j]=='O'){
                  qu.push({board.size()-1,j});
                  board[board.size()-1][j]='1';
                }
              }
        }
        
        bfs(board);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='1') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};


//solution 2  time efficient
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        vector<vector<char>> ans_board(board.size(),vector<char> (board[0].size(),'X'));
        int rows=board.size();
        int cols=board[0].size();
        queue<pair<int,int>> qu;
        bool flag=false;
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O'){
                flag=true;
                board[i][0]='V';
                qu.push({i,0});
            }
            if(board[i][cols-1]=='O'){
                flag=true;
                board[i][cols-1]='V';
                qu.push({i,cols-1});
            }
        }
        for(int j=1;j<cols-1;j++){
            if(board[0][j]=='O'){
                flag=true;
                board[0][j]='V';
                qu.push({0,j});
            }
            if(board[rows-1][j]=='O'){
                flag=true;
                board[rows-1][j]='V';
                qu.push({rows-1,j});
            }
        }
        
        if(!flag){
            board=ans_board;
            return;
        }

        
        while(!qu.empty()){
            auto ele=qu.front();
            qu.pop();
            int row=ele.first;
            int col=ele.second;
            ans_board[row][col]='O';
            for(int d=0;d<4;d++){
                int new_row=row+dir[d][0];
                int new_col=col+dir[d][1];
                if(new_row<0 || new_col<0 || new_row>=rows || new_col>=cols) continue;
                if(board[new_row][new_col]=='X' || board[new_row][new_col]=='V') continue;
                ans_board[new_row][new_col]='O';
                board[new_row][new_col]='V';
                qu.push({new_row,new_col});
            }
        }
        board=ans_board;
    }
};