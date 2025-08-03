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

     Matrix operator+(Matrix m2);
     Matrix operator-(Matrix m2);
     void operator+=(Matrix m2);
     void operator-=(Matrix m2);
};
Matrix Matrix::operator+(Matrix m2){
    Matrix m3(this->v.size(),this->v[0].size());
    for(int i=0;i<this->v.size();i++){
        for(int j=0;j<this->v[i].size();j++){
            m3.v[i][j]=this->v[i][j]+m2.v[i][j];
        }
    }
    return m3;
}

Matrix Matrix::operator-(Matrix m2){
    Matrix m3(this->v.size(),this->v[0].size());
    for(int i=0;i<this->v.size();i++){
        for(int j=0;j<this->v[i].size();j++){
            m3.v[i][j]=this->v[i][j]-m2.v[i][j];
        }
    }
    return m3;
}

void Matrix::operator+=(Matrix m2){

    for(int i=0;i<this->v.size();i++){
        for(int j=0;j<this->v[i].size();j++){
            this->v[i][j]+=m2.v[i][j];
        }
    }
   
}
void Matrix::operator-=(Matrix m2){
    
    for(int i=0;i<this->v.size();i++){
        for(int j=0;j<this->v[i].size();j++){
            this->v[i][j]-=m2.v[i][j];
        }
    }
  
}
int main(){
    Matrix m1(2,3);
    Matrix m2(2,3);

    m1.set_data();
    m2.set_data();
    m1.get_data();
    m2.get_data();

    Matrix m3;
    m3=m1+m2;
    cout<<"adding matrix:\n";
    m3.get_data();

    Matrix m4;
    m4=m1-m2;
    cout<<"subtracting matrix:\n";
    m4.get_data();

    Matrix m5;
    m5=m1;  //it is already overloaded.
    cout<<"assigning matrix:\n";
    m5.get_data();

    m1+=m2;
    m3-=m4;
    cout<<"addition assignment:\n";
    m1.get_data();
    cout<<"subtraction assignment:\n";
    m3.get_data();

    return 0;
}