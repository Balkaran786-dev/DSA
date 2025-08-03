#include<bits/stdc++.h>
using namespace std;
class Matrix{
   vector<vector<int>> v;
   public:
     Matrix(){}
     Matrix(int rows,int columns){
        this->v.resize(rows);
        for(int i=0;i<rows;i++){
            this->v[i].resize(columns);
        }
     }

     void set_data(){
        for(int i=0;i<this->v.size();i++){
            for(int j=0;j<this->v[i].size();j++){
                cin>>this->v[i][j];
            }
        }
     }

     void get_data(){
        cout<<"printing the matrix:- "<<endl;
        for(int i=0;i<this->v.size();i++){
            for(int j=0;j<this->v[i].size();j++){
                cout<<this->v[i][j]<<" ";
            }
            cout<<endl;
        }
     }

     ~Matrix(){
        cout<<"Destructor is called\n";
     }

     Matrix operator*(Matrix m2);
     void operator*=(Matrix m2);
};

Matrix Matrix::operator*(Matrix m){
     Matrix ans(this->v.size(),m.v[0].size());
     for(int i=0;i<v.size();i++){
        for(int j=0;j<m.v[0].size();j++){
            int a=0;
            for(int k=0;k<m.v.size();k++){
               a+=this->v[i][k]*m.v[k][j];
            }
            ans.v[i][j]=a;
        }
    }
    return ans;
}

void Matrix::operator*=(Matrix m){
     for(int i=0;i<v.size();i++){
        for(int j=0;j<m.v[0].size();j++){
            int a=0;
            for(int k=0;k<m.v.size();k++){
               a+=this->v[i][k]*m.v[k][j];
            }
            v[i][j]=a;
        }
    }
}
int main(){
    Matrix m1(2,3);
    Matrix m2(3,3);

    m1.set_data();
    m2.set_data();
    m1.get_data();
    m2.get_data();

    Matrix mul;
    mul=m1*m2;
    mul.get_data();

    mul*=m2;
    mul.get_data();
    return 0;
}