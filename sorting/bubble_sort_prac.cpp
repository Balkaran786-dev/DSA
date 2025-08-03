#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &vec,int n){

       for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=0;j<=n-2-i;j++){
            if(vec[j]>vec[j+1]){
                flag=true;
                swap(vec[j],vec[j+1]);
            }
        }
        if(!flag){
            break;
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

    bubblesort(vec,n);
    
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    return 0;

}