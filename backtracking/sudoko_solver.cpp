/*
 $$-- if we have a digit at that place,we will just move to next element.
 $$-- whenever im getting a '.' while traversing the grid,i have total 9 possibilities(1-9) that 
 we can place over that place,we will check one by one from 1-9,if we can place some number,
 we will update that in grid and we move to next element.
 $$-- if at some element,we are not able to place any number at there,we will return false,
    when we get false as returned value,we need to change the current element to some other number.
 $$-- when this function return true,we will just return true.Also,it only returns true in case we have completely filled the grid.
 $$-- this function will be returning a boolean value,because we are not printing or like storing 
 our answer at the base case like we did in queen problem,so after getting the ans,if we just return back,it will revert back all the changes that 
 we would have done in our grid.
*/

#include<iostream>
#include<vector>
using namespace std;
class solution{
public:
       bool CanWePlace(vector<vector<char>> &grid,int row,int col,int num){
            for(int i=0;i<9;i++){    //for checking in the column
                if(grid[i][col]=='0'+num){
                    return false;
                }
            }
            for(int j=0;j<9;j++){    //for checking in the row
                if(grid[row][j]=='0'+num){
                    return false;
                }
            }
            //c,d gives the first coordinate of every 3*3 subgrid. we basically assumed our whole grid to be divided into 9 subgrids.
            int c=(row/3)*3;      //3*3 subgrid.
            int d=(col/3)*3;
            for(int i=c;i<(c+3);i++){

                for(int j=d;j<(d+3);j++){
                    if(grid[i][j]=='0'+num){
                    return false;
                    }

                }
            }

            return true;
       }
       bool sudoko(vector<vector<char>> &grid,int row,int col){
            if(col==9) return sudoko(grid,row+1,0);   //when col variable recahes out of gris,we need to move to next row and 0th column
            if(row==9) return true;                 //when we reaches out of rows,means we have successfully placed our digits in our grid,hence returns true
            if(grid[row][col]=='.'){          //if curr ele is '.'
                for(int num=1;num<=9;num++){
                    if(CanWePlace(grid,row,col,num)){
                        grid[row][col]='0'+num;
                        bool res=sudoko(grid,row,col+1);  //if it returns false,we need to revert make our change.
                        if(res) return true;  
                        grid[row][col]='.';   //reverting back our changes that we made in grid.
                        
                    }
                }
                return false;  //when not able to place anything
            }
            else{
                return sudoko(grid,row,col+1);
            }
       }
       void sudoko_solver(vector<vector<char>> &grid){
               if(sudoko(grid,0,0)){  //if it returns true,means it can be solved 
                  for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        cout<<grid[i][j]<<" ";
                    }
                    cout<<"\n";
                  }
               }
               else{
                cout<<"IT CAN'T BE SOLVED";
               }
       }
};
int main(){
    solution s;
    vector<vector<char>> grid={

        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    s.sudoko_solver(grid);
    return 0;
}


