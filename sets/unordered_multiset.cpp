#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_multiset<int> ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(8);
    ms.insert(4);
    ms.insert(7);

    for(auto ele:ms){
        cout<<ele<<" ";
    }cout<<endl;
    return 0;
}