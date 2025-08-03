#include<iostream>
#include<vector>
using namespace std;
void f(vector<int> v){
    if(v.size()==0){
        // cout<<v[0]<<" ";
        return;
    }
    
    for(int i=0;i<v.size()-1;i++){
        v[i]=v[i]+v[i+1];
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    v.pop_back();

    f(v);
}
int main(){
    // vector<int> v={5,4,3,2,1};
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // f(v);
    vector<int> a;
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    int last_ele=a.back();
    cout<<last_ele<<" ";
    a.pop_back();
    cout<<a.back();
    return 0;
}