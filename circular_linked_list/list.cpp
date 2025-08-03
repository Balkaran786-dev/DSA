#include<iostream>
#include<list>
using namespace std;
int main(){
    
    list<int>  l1={1,2,3,4};
    auto itr=l1.begin();  //this will be giving an iterator for the above conatiner only due to l1.
                          //or you can use list<int>::iterator itr;
    //l1.end() is pointing to the memory location after 4.
    cout<<*itr<<endl;
    
    // auto itr_rev=l1.rbegin();
    // cout<<*itr_rev<<endl;
    
    advance(itr,2);
    cout<<*itr<<endl;


    //Normal Traversal through list.
    //using range-based loop.
    // for(auto num:l1){
    //     cout<<num<<endl;  //in every iteration,instances are form for every element present in l1.
    // }
    // //using iterators...
    // for(auto itr=l1.begin(); itr!=l1.end(); itr++){
    //     cout<<*itr<<" ";
    // }cout<<endl; 


    // //reverse traversal:
    // for(auto itr=l1.rbegin();itr!=l1.rend();itr++){
    //     cout<<*itr<<" ";
    // }cout<<endl;


    // //INSERTION
    // list<int> l2={1,2,3,4,5};
    // auto itr=l2.begin();
    // advance(itr,2);
    // // l2.insert(itr,6);
    // // for(auto temp=l2.begin();temp!=l2.end();temp++){
    // //     cout<<*temp<<" ";
    // // }cout<<endl;

    // // l2.insert(itr,2,6);
    // // for(auto temp=l2.begin();temp!=l2.end();temp++){
    // //     cout<<*temp<<" ";
    // // }cout<<endl;

    // auto l=l2.begin();
    // auto r=l2.begin();
    // advance(r,2);
    // l2.insert(itr,l,r);
    // for(auto temp=l2.begin();temp!=l2.end();temp++){
    //     cout<<*temp<<" ";
    // }cout<<endl;

    // //1 2 1 2 3 4 5   we need to keep 1 2 only single time
    // auto s_itr=l2.begin();
    // advance(s_itr,2); //s_itr pointing to 3rd element
    // auto e_itr=l2.begin();
    // advance(e_itr,4); //e_itr pointing to 5th lelemnt
    // l2.erase(s_itr,e_itr);
    // for(auto temp=l2.begin();temp!=l2.end();temp++){
    //     cout<<*temp<<" ";
    // }cout<<endl;
    return 0;
}