#include<iostream>
#include<set>
using namespace std;
int main(){
    // set<int> set1;
    // //Insertion
    // set1.insert(1);
    // set1.insert(2);
    // set1.insert(3);
    // cout<<set1.size()<<endl;
    // set1.insert(3);
    // cout<<set1.size()<<endl;

    // set<int>::iterator itr;
    // for(itr=set1.begin();itr!=set1.end();itr++){
    //     cout<<*itr<<" ";
    // }cout<<endl;

    // set<int,greater<int>> set2;
    // set2.insert(1);
    // set2.insert(2);
    // set2.insert(3);
    // set<int>::iterator iter;
    // for(iter=set2.begin();iter!=set2.end();iter++){
    //     cout<<*iter<<" ";
    // }cout<<endl;


    // //Traversal by For each loop.
    // for(auto value:set2){  //auto apne aap data-type infer kardega.value 
    //    cout<<value<<" ";   //kyunki set1 mein hai and set1 int datatype ka hai.so because of auto,
    // }cout<<endl;           //value ko int datatype ka bna dega..
    
    //DELETION:
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(8);
    s1.insert(9);


    for(auto value:s1){  
       cout<<value<<" ";   
    }cout<<endl;

// //1.
//     s1.erase(4);
//     for(auto value:s1){  
//        cout<<value<<" ";   
//     }cout<<endl;

// //2.
    // auto itr=s1.begin();
    // advance(itr,3);
    // s1.erase(itr);
    // for(auto value:s1){  
    //    cout<<value<<" ";   
    // }cout<<endl;
// //3.
    // auto start_itr=s1.begin();
    // start_itr++;
    // auto end_itr=s1.begin();
    // advance(end_itr,3);
    // s1.erase(start_itr,end_itr);
    // for(auto value:s1){  
    //    cout<<value<<" ";   
    // }cout<<endl;

    //search operation.
    // if(s1.find(5)!=s1.end()){
    //     cout<<"value is present\n";
    // }
    // else{
    //     cout<<"value is not present\n";
    // }
    // auto it=s1.find(10);
    // cout<<*it;
    //LOWER_BOUND  AND UPPER_BOUND:
    //LOWER_BOUND
    // set<int> s2;
    // s2.insert(10);
    // s2.insert(40);
    // s2.insert(30);
    // s2.insert(50);
    // //case1.  given key is not presnt
    // auto i1=s2.lower_bound(20);
    // if(i1!=s2.end()){
    //     cout<<"The lower bound to 20 is:"<<*i1<<endl;
    // }
    // else{
    //     cout<<"The specified value is greater than the maximum value is the set.\n";
    // }
    // //case2.  given key is present
    // auto i2=s2.lower_bound(30);
    // if(i2!=s2.end()){
    //     cout<<"The lower bound to 30 is:"<<*i2<<endl;
    // }
    // else{
    //     cout<<"The specified value is greater than the maximum value is the set.";
    // }
    // //case3.   given key is greater than the maximum value of the set
    // auto i3=s2.lower_bound(80);
    // if(i3!=s2.end()){
    //     cout<<"The lower bound to 80 is:"<<*i3<<endl;
    // }
    // else{
    //     cout<<"The specified value is greater than the maximum value is the set.";
    // }

    //UPPER_BOUND;
    //case1.  given key is not presnt
    // auto i1=s2.upper_bound(20);
    // if(i1!=s2.end()){
    //     cout<<"The upper bound to 20 is:"<<*i1<<endl;
    // }
    // else{
    //     cout<<"The specified value is greater than the maximum value is the set.\n";
    // }
    //case2.  given key is present
    // auto i2=s2.upper_bound(30);
    // if(i2!=s2.end()){
    //     cout<<"The lower bound to 30 is:"<<*i2<<endl;
    // }
    // else{
    //     cout<<"The specified value is greater than the maximum value is the set.";
    // }
    // //case3.   given key is equal to or greater than the maximum value of the set
    // auto i3=s2.upper_bound(80);
    // if(i3!=s2.end()){
    //     cout<<"The lower bound to 80 is:"<<*i3<<endl;
    // }
    // else{
    //     cout<<"The specified value is greater than the maximum value is the set.";
    // }
//    set<int> s2;
//     s2.insert(10);
//     s2.insert(40);
//     s2.insert(30);
//     s2.insert(5);
//    set<int> :: reverse_iterator itr;
//    for(itr=s2.rbegin();itr!=s2.rend();itr++){
//      cout<<*itr<<" ";
//    }
}