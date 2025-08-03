#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> invite_list;
    int n;
    cin>>n;
    while(n--){
        string name;
        cin>>name;
        invite_list.insert(name);
    }

    for(auto ele:invite_list){
        cout<<ele<<" ";
    }
}