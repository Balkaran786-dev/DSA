//bruteforce solution:
/*Take every single element from 1st vector and compare it with every single
  ele of second vector.If ele comes out to be same,add it in the sum.*/


//Optimised approach:
/*pass all elements of vector to a set to remove duplicates.since insertion has time complexity of - o(log(no_of_ele_in_set)),
  and total elements in vector is N,so Nlog(T),where T is no_of unique elements in set.

  then you search each of these M elements of vector second in these T elements.Since searching has time complexity of - o(log(no_of_ele_in_set)),
  so,MlogT becomes the time complexity here.

  total time complexity-o((n+m)logt)
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    // int n,m;
    // cin>>n>>m;
    // vector<int> v1(n);
    // vector<int> v2(m);
    // for(int i=0;i<n;i++){
    //     cin>>v1[i];
    // }
    // for(int i=0;i<m;i++){
    //     cin>>v2[i];
    // }
    // set<int> s1;
    // int ans_sum=0;
    // for(auto ele:v1){
    //     s1.insert(ele);
    // }

    // for(auto ele:v2){
    //     if(s1.find(ele)!=s1.end()){
    //         s1.erase(ele);      //agar v2 mein duplicates huye jo s1 mein bhi present huye toh vo ek se jada times add ho jayenge
    //                             //in order to ensue that this doesn't happen,we will remove the ele once its same ele in present in s1.
    //         ans_sum+=ele;
    //     }
    // }
    // cout<<ans_sum<<endl;
    // return 0;

    string str="abcdEFGHI";
    set<char> s1;
    for(char ele:str){
        s1.insert(ele);
    }
    for(auto value:s1){  
       cout<<value<<" ";   
    }cout<<endl;
}