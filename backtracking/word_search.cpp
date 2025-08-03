class Solution {
public:
    bool if_present(vector<vector<char>>& board,int i,int j,string word,int idx){
            if(idx==word.size()){
                return true;
            }
            
            char ch=board[i][j];
            board[i][j]='1';   //Done it so that while further calls,we don't get back to it
            if(i+1<board.size() && board[i+1][j]==word[idx]){
                bool res=if_present(board,i+1,j,word,idx+1);
                if(res) return true;
            }
            if(i-1>=0 && board[i-1][j]==word[idx]){
                bool res=if_present(board,i-1,j,word,idx+1);
                if(res) return true;
            }
            if(j+1<board[0].size() && board[i][j+1]==word[idx]){
                bool res=if_present(board,i,j+1,word,idx+1);
                if(res) return true;
            }
            if(j-1>=0 && board[i][j-1]==word[idx]){
                bool res=if_present(board,i,j-1,word,idx+1);
                if(res) return true;
            }
            board[i][j]=ch;
            return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    bool res=if_present(board,i,j,word,1);
                    if(res){
                        return true;
                    }
                }
            }
        } 

        return false;
    }
};