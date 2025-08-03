/*#include<iostream>
#include<vector>
using namespace std;
int rowofmaxones(vector<vector<int>> v){
    int rowwithmaxones=-1;
    int maxones=-1;
    for(int i=0;i<v.size();i++){
        int ones=0;
        for(int j=v[0].size()-1;j>=0;j--){
            if(v[i][j]==0){
                break;
            }
            else{
               ones+=1;
            }
        }
        if(maxones<ones){
            maxones=ones;
            rowwithmaxones=i;
        }
    }
    return rowwithmaxones;
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
    cout<<rowofmaxones(vec);
}

//or
#include<iostream>
#include<vector>
using namespace std;
int rowsWithMax1(vector<vector<int>> v){
    int maxones=INT16_MIN;
    int rowsOfMaxOnes=-1;
    int columns=v[0].size();
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
              int noOfOnes=columns-j;
            if(noOfOnes>maxones){
            maxones=noOfOnes;
            rowsOfMaxOnes=i;
            }
            break;
            }
        }
       
    }
    return rowsOfMaxOnes;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<rowsWithMax1(v);
    return 0;
}*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotation(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){   // transpose of matrix having equal rows and columns without taking extra space
            if(i!=j && i<j){
               swap(v[i][j],v[j][i]);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        reverse(v[i].begin(),v[i].end());
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    rotation(v);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}
