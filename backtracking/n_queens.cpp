// #include<iostream>
// #include<vector>
// using namespace std;
// // bool CanPlaceQueen(int row,int col,vector<vector<char>> &grid){
// //       //attack agar hoga toh upper se hi ho skta hai,
// //       //beacuse curr row ke neeche toh sabh khali hai.

// //       for(int i=row-1;i>=0;i--){  //vertical attack from upward.
// //         if(grid[i][col]=='Q'){
// //             return false;
// //         }
// //       }

// //       for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){   //diagonal attack from left side
// //         if(grid[i][j]=='Q'){
// //             return false;
// //         }
// //       }

// //       for(int i=row-1,j=col+1; i>=0 && j<=grid.size()-1; i--,j++){   //diagonal attack from right side
// //         if(grid[i][j]=='Q'){
// //             return false;
// //         }
// //       }

// //       return true;
// // }
// // void n_queens(vector<vector<char>> &grid,int curr_row ,int n){
// //     if(curr_row==n){
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<n;j++){
// //                 cout<<grid[i][j]<<" ";
// //             }
// //             cout<<"\n";
// //         }
// //         cout<<"******\n";
// //         return;
// //     }

// //     for(int col=0;col<n;col++){
// //         if(CanPlaceQueen(curr_row,col,grid)){
// //             grid[curr_row][col]='Q';
// //             n_queens(grid,curr_row+1,n);
// //             grid[curr_row][col]='.';
// //         }
// //     }
// // }

// // int main(){
// //     int n=4;
// //     vector<vector<char>> grid(n,vector<char> (n,'.'));
// //     n_queens(grid,0,n);
// //     return 0;
// // }

// // class Solution {
// // public:
// //     vector<vector<char>> grid;
// //     bool can_we_place(int row,int col){
// //         //it can only attack from above
// //         //checking vertical attack
// //         for(int i=row-1;i>=0;i--){
// //             if(grid[i][col]=='Q'){
// //                 return false;
// //             }
// //         }
// //         //checking diagonal attack from left.
// //         for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--){
// //             if(grid[i][j]=='Q'){
// //                 return false;
// //             }
// //         }
// //         //checking diagonal attack from right.
// //         for(int i=row-1,j=col+1;i>=0,j<grid[0].size();i--,j++){
// //             if(grid[i][j]=='Q'){
// //                 return false;
// //             }
// //         }
// //         return true;
// //     }
    
// //     void n_queen(int &count,int row,int n){
// //         if(row==n){
// //             count++;
// //             return;
// //         }

// //         for(int col=0;col<=n-1;col++){
// //            if(can_we_place(row,col)){
// //              grid[row][col]='Q';
// //              n_queen(count,row+1,n);
// //              grid[row][col]='.';
// //            }
// //         }
// //     }
// //     int totalNQueens(int n) {
// //         grid.resize(n);
// //         for(int i=0;i<n;i++){
// //             grid[i].resize(n,'.');
// //         }
// //         int count=0;
// //         n_queen(count,0,n);
// //         return count;
// //     }
// // };
// // int main(){
// //     Solution s;
// //     cout<<s.totalNQueens(3);
// // }

// class Solution {
// public:
//     vector<vector<char>> grid;
    
//     bool can_we_place(int row, int col) {
//         // Check vertical attack
//         for (int i = row - 1; i >= 0; i--) {
//             if (grid[i][col] == 'Q') {
//                 return false;
//             }
//         }
//         // Check diagonal attack from left
//         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//             if (grid[i][j] == 'Q') {
//                 return false;
//             }
//         }
//         // Check diagonal attack from right
//         for (int i = row - 1, j = col + 1; i >= 0 && j < grid[0].size(); i--, j++) {
//             if (grid[i][j] == 'Q') {
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     void n_queen(int &count, int row, int n) {
//         if (row == n) {
//             count++;
//             return;
//         }

//         for (int col = 0; col <= n - 1; col++) {
//             if (can_we_place(row, col)) {
//                 grid[row][col] = 'Q';
                
//                 n_queen(count, row + 1, n);
//                 grid[row][col] = '.';
                
//             }
//         }
//     }
    
//     int totalNQueens(int n) {
//         grid.resize(n);
//         for (int i = 0; i < n; i++) {
//             grid[i].resize(n, '.');
//         }
//         int count = 0;
//         n_queen(count, 0, n);
//         return count;
//     }
// };
// int main(){
//     // Solution s;
//     // cout<<s.totalNQueens(7);

//     char ch='0'+1;
//     cout<<ch;
// }


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool can_we_place(vector<vector<char>>& board,int digit,int row,int col){
          for(int r=0;r<9;r++){
              if(board[r][col]=='0'+digit) return false;
          }
          for(int c=0;c<9;c++){
              if(board[row][c]=='0'+digit) return false;
          }
          int r=(row/3)*3;
          int c=(col/3)*3;
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[r+i][c+j]=='0'+digit) return false;
            }
          }

          return true;//if everything is all set 
    }
    bool get_sudoku_table(vector<vector<char>>& board,int row,int col){
        if(row==9){
            return true;
        }
        else if(col==9){
            return get_sudoku_table(board,row+1,0);
        }
        else if(board[row][col]=='.'){
            for(int i=1;i<=9;i++){
                if(can_we_place(board,i,row,col)){
                    board[row][col]='0'+i;
                    bool res=get_sudoku_table(board,row,col+1);
                    if(res){
                        return true;
                    }
                    board[row][col]='.';
                }
            }
            return false;
        }
        else{
            return get_sudoku_table(board,row,col+1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool res=get_sudoku_table(board,0,0);
    }
};

int main(){
    vector<vector<char>> v;
    v={{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    s.solveSudoku(v);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}