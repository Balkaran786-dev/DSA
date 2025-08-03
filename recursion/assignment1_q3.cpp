#include<bits/stdc++.h>
using namespace std;
void print_ele(vector<int> &temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
void comb(vector<int> &A,vector<int> &B,int idx1,int idx2,vector<int> &temp){
    if(!temp.empty()) print_ele(temp);

    if(idx1>=A.size() || idx2>=B.size()){
        temp.pop_back();
        return;
    }

    for(int i=idx1;i<A.size();i++){
        if(temp.empty() || temp.back()<A[i]) temp.push_back(A[i]);
        else continue;

        for(int j=idx2;j<B.size();j++){
            if(temp.back()<B[j]){
                temp.push_back(B[j]);
                comb(A,B,i+1,j+1,temp);
            }
        }
        temp.pop_back();
    }
    temp.pop_back();
}
int main(){
    vector<int> A={10,15,25,39};
    vector<int> B={1,5,20,30};
    vector<int> temp;
    comb(A,B,0,0,temp);
    return 0;
}