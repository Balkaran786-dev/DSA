#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &vec,int n){
    for(int i=0;i<=n-2;i++){
        int min_index=i;
        
        for(int j=i+1;j<n;j++){
            if(vec[j]<vec[min_index]){
                min_index=j;
            }
        }

        if(min_index!=i){
            swap(vec[i],vec[min_index]);
        }
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

    
    selection_sort(vec,n);
    
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}