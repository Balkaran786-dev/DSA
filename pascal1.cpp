#include<iostream>
#include<vector>
using namespace std;
int max_ones_row(vector<vector<int>> vec){
    int row_with_max_ones=-1;
    int left_most_column=INT16_MAX;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            if(vec[i][j]==1){
                if(j<left_most_column){
                    left_most_column=j;
                    row_with_max_ones=i;
                    break;
                }
            }
        }
    }
    return row_with_max_ones;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          cin>>vec[i][j];
        }
    }
    cout<<max_ones_row(vec);
    
    return 0;
}