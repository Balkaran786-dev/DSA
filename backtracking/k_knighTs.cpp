//iss mein hum base case mein hi print kr rhe hein so no need of boolean function.
//abb jab hum after the knights function,jab main function mein print krenge grid ko,then it will be empty,
//kyunki saare changes revert back ho gaye honge.

#include<iostream>
#include<vector>
using namespace std;
bool CanWePlace(vector<vector<char>> &grid,int i,int j){
    if(i-1>=0 && j-2>=0 && grid[i-1][j-2]=='K') return false;  //pehle check kro sabhi cases mein ki voh inside the 
                                                               //grid hein,then check ki vahan k present toh nhi hai.....
    if(i-1>=0 && j+2<grid[0].size() && grid[i-1][j+2]=='K') return false;
    if(i-2>=0 && j-1>=0 && grid[i-2][j-1]=='K') return false;
    if(i-2>=0 && j+1<grid[0].size() && grid[i-2][j+1]=='K') return false;
     return true;
}

void knights(vector<vector<char>> &grid,int i,int j,int k){
    if(k==0){   //all are placed 
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            cout<<(grid[i][j]=='K'? 'K': '_');
        }
        cout<<"\n";
       }
       cout<<"******\n";
       return;
    }

    if(j==grid[0].size()) return knights(grid,i+1,0,k);
    if(i==grid.size()) return;  //obviously,saare k placed nhi hue,isliye return kro.

    for(int row=i;row<grid.size();row++){  //har ek knight ko har ek box mein rakh kar dekhenge starting from ith row jth column box...
        for(int col=(row==i?j:0);col<grid[0].size();col++){ //hum uss row mein toh col se shuru krenge place krna uske
                                                            //age vali sari rows ke liye toh sari columns starting from zero se check krenge.
            if(CanWePlace(grid,row,col)){
                grid[row][col]='K';             //we will place that k here.
                knights(grid,row,col+1,k-1);
                grid[row][col]=' ';       //agr hum return kre toh hume apni position of k change krni hogi.
            }
        }
    }
}

int main(){
    int m=3;
    int n=3;
    int k=5;
    vector<vector<char>> grid(m,vector<char> (n,' '));
    knights(grid,0,0,k);
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            cout<<(grid[i][j]=='K'? 'K': '_');
        }
        cout<<"\n";
     }
}
