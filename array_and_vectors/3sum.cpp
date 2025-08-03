// #include<bits/stdc++.h>
// using namespace std;//bruteforce solution
// vector<vector<int>> three_sum(vector<int> &v){
//     set<vector<int>> st;   //because hume unique set of values chahiye
//     for(int i=0;i<v.size();i++){
//         for(int j=i+1;j<v.size();j++){
//             for(int k=j+1;k<v.size();k++){
//                 if(v[i]+v[j]+v[k]==0){
//                     vector<int> temp={v[i],v[j],v[k]};
//                     sort(temp.begin(),temp.end());  //hum vector sort krke fer set mein dalenge, otherwise set will consider {2,1,-1} and {-1,2,1} as unequal,but 
//                                                   //if we sort them both become {-1,1,2} hnec will be stored only one time in set
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans;

//     ans.assign(st.begin(),st.end());
//     return ans;
// }
// int main(){
//     vector<int> v={-1,0,1,2,-1,-4};
//     vector<vector<int>> ans=three_sum(v);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;//bruteforce solution
vector<vector<int>> three_sum(vector<int> &v){
    unordered_set<int> temp;  //o(n^2) time
                               //o(n)+o(no.of unique triplets)*2;

    set<vector<int>> st;
    for(int i=0;i<v.size();i++){   
        for(int j=i+1;j<v.size();j++){
         int ele3=-(v[i]+v[j]);
         if(temp.count(ele3)){
            vector<int> vec={v[i],v[j],ele3};
            sort(vec.begin(),vec.end());
            st.insert(vec);
         }
         temp.insert(v[j]);
        }
        temp.clear();
    } 
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
int main(){
    vector<int> v={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=three_sum(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}