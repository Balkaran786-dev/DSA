class Solution {
public:

    bool is_it_ok(vector<vector<char>>& board,char digit,int row,int col){
        board[row][col]='.';
          for(int r=0;r<9;r++){
              if(board[r][col]==digit){
                board[row][col]=digit;
                return false;
              }
          }
          for(int c=0;c<9;c++){
              if(board[row][c]==digit){
                board[row][col]=digit;
                return false;
              }
          }
          int r=(row/3)*3;
          int c=(col/3)*3;
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[r+i][c+j]==digit){
                    board[row][col]=digit;
                    return false;
                }
            }
          }
          board[row][col]=digit;
          return true;//if everything is all set 
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch!='.'){
                    bool res=is_it_ok(board,ch,i,j); //it will check whether ,that number is not present again horizontally,vertically or in the subgrid.
                    if(!res){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};