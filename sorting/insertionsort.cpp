#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int> &v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int current_ele=v[i];
        int j=i-1;
        for( ;j>=0;j--){
           if(v[j]>current_ele){
             v[j+1]=v[j];
           }
           else{
            break;
           }
        }
        v[j+1]=current_ele;
    }
    return;
}
int main(){
    vector<int> vec={7,3,9,2,1,4};
    insertionsort(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}