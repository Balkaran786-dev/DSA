// #include<iostream>
// #include<unordered_set>
// #include<vector>
// using namespace std;
// int main(){
//     //at every question,im taking either p or q or 0.
//     int n,p,q;
//     cin>>n>>p>>q;
//     unordered_set<int> scores;                //mam's tatti solution
//     for(int i=0;i<=n;i++){    //correct question  
//         for(int j=0;j<=n;j++){   //incorrect question
//             int unattended_ques=n-(i+j);
//             if(unattended_ques>=0){
//                 scores.insert(i*p+j*q);
//             }
//         }
//     }
//     cout<<scores.size();
    
// }



#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
void get_possible_ans(int n,int p,int q,int temp,vector<int> marks,unordered_set<int> &ans){
    if(n==0){
        ans.insert(temp);
        return;
    }

    for(int i=0;i<marks.size();i++){ //I'm expecting that mein curr question ke 
        temp+=marks[i];
        get_possible_ans(n-1,p,q,temp,marks,ans);
        temp-=marks[i]; //uss mark ko delete bhi krna hai taki same question ke same diff cases check kr payen...
    }
}
int main(){
    //at every question,im taking either p or q or 0.
    int n,p,q;
    cin>>n>>p>>q;
    vector<int> marks={p,q,0};
    unordered_set<int> possible_ans;
    get_possible_ans(n,p,q,0,marks,possible_ans);
    for(auto ele:possible_ans){
        cout<<ele<<" ";
    }
}