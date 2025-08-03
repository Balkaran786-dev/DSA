#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> & vec,int n){
     for(int i=1;i<n;i++){
        int key=vec[i];
        int j=i-1;
        for(;j>=0;j--){
            if(vec[j]>key){
                vec[j+1]=vec[j];
            }
            else{
                break;
            }
        }
        vec[j+1]=key;
     }
}
int main(){
    
    int n;
    cout<<"Size of vector:- ";
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    insertion_sort(vec,n);
    
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}