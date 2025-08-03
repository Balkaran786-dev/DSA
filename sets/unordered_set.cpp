#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> un_set;
    un_set.insert(2);
    un_set.insert(1);
    un_set.insert(3);
    un_set.insert(2);
    for(auto value:un_set){
        cout<<value<<" ";
    }
}