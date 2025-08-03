#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap<string,int> fruit_count;
    fruit_count.insert(make_pair("Banana",56));
    fruit_count.insert(make_pair("Apple",45));
    fruit_count.insert(make_pair("Apple",6));
    fruit_count.insert(make_pair("guava",6));
    for(auto ele:fruit_count){
        cout<<ele.first<<"-"<<ele.second<<endl;
    }
    return 0;
}