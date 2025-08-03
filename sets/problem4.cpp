//when we are using a multiset

// #include<iostream>
// #include<set>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cout<<"The counting of numbers:";
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     multiset<int> ms;
//     for(auto ele:v){
//         ms.insert(ele);
//     }
//     int smallest_ele_count=ms.count(*(ms.begin()));
//     auto itr=ms.begin();
//     advance(itr,smallest_ele_count);
//     cout<<*itr;

//     return 0;
// }


//when we are using a ordered_set:

#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"The counting of numbers:";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int> ms;
    for(auto ele:v){
        ms.insert(ele);
    }
    auto itr=ms.begin();
    advance(itr,1);
    cout<<*itr;

    return 0;
}