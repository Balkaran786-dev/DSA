#include<iostream>
using namespace std;
int main(){
    int rows1;
    cin>>rows1;
    int columns1;
    cin>>columns1;
    int A[rows1][columns1];
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns1;j++){
            cin>>A[i][j];
        }     
    }
    int rows2;
    cin>>rows2;
    int columns2;
    cin>>columns2;
    int B[rows2][columns2];
    for(int i=0;i<rows2;i++){
        for(int j=0;j<columns2;j++){
            cin>>B[i][j];
        }     
    }
    int C[rows1][columns2];
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            int ans=0;
            for(int k=0;k<rows2;k++){
               ans+=A[i][k]*B[k][j];
            }
            C[i][j]=ans;
        }
    }
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;     
    }
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int rows1;
    cin>>rows1;
    int columns1;
    cin>>columns1;
    int array[rows1][columns1];
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns1;j++){
            cin>>array[i][j];
        }     
    }
    int rows2=columns1;
    int columns2=rows1; 
    int Transposedarray[rows2][columns2];
    for(int i=0;i<rows2;i++){
        for(int j=0;j<columns2;j++){
            Transposedarray[i][j]=array[j][i];
        }
    }
    for(int i=0;i<rows2;i++){
        for(int j=0;j<columns2;j++){
            cout<<Transposedarray[i][j]<<" ";
        }
        cout<<endl;     
    }
    return 0;
}