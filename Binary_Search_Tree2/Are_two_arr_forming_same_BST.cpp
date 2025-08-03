#include<bits/stdc++.h>
using namespace std;
bool check_identical_BST(vector<int> &v1,vector<int> &v2,int a1,int a2,int min_val,int max_val){
    
    //first find that element that comes in the given range in both the arrays one by one..
    int i; //to find ele in first array between the range
    for(i=a1;i<v1.size();i++){
        if(v1[i]>min_val && v1[i]<max_val) break;
    }

    int j;  //to find ele in second array between the range
    for(j=a2;j<v2.size();j++){
        if(v2[j]>min_val && v2[j]<max_val) break;
    }
     
     //ele is not found in both the arrays 
    if(i==v1.size() && j==v2.size()) return true;

    //ele only found in one array
    if((i==v1.size() && j!=v2.size()) || (i!=v1.size() && j==v2.size())) return false;

    //ele found in both arrays are not equal
    if(v1[i]!=v2[j]) return false;

    //ele found is same,so we will check in left and right subtree by incrementing a1 and a2 
    //and changing the min_val and max_val;


    return check_identical_BST(v1,v2,a1+1,a2+1,min_val,v1[i]) && check_identical_BST(v1,v2,a1+1,a2+1,v1[i],max_val);

}
bool if_same(vector<int> &v1,vector<int> &v2){
    return check_identical_BST(v1,v2,0,0,INT_MIN,INT_MAX);
}
int main(){
    vector<int> v1={4,2,5,1,3};
    vector<int> v2={4,5,2,3,1};
    if(if_same(v1,v2)){
        cout<<"Identical";
    }
    else{
        cout<<"Not Identical";
    }
    
    return 0;
}