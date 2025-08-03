#include<bits/stdc++.h>
using namespace std;
void get_sliding_window_max(vector<int> &vec,int k,vector<int> &max_sliding_window){
    queue<int> qu;
    for(int i=0;i<k;i++){
        while(!qu.empty() && qu.back()<=vec[i]){
            qu.pop();
        }
        qu.push(vec[i]);
    }

    max_sliding_window.push_back(qu.front());
    for(int i=k;i<vec.size();i++){
        while(!qu.empty() && qu.back()<=vec[i]){
            qu.pop();
        }

        if(qu.size()==k){
            qu.pop();
        }

        qu.push(vec[i]);

        max_sliding_window.push_back(qu.front());
    }
}
int main(){
    int k;
    cin>>k;
    
    int n;
    cin>>n;
    vector<int> vec(n);
    vector<int> max_sliding_window;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    get_sliding_window_max(vec,k,max_sliding_window);
    for(int i=0;i<max_sliding_window.size();i++){
          cout<<max_sliding_window[i]<<" ";
    }
    return 0;
}