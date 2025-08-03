#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> directory;  //ascending order.
    directory={{"Balkaran",8759},{"Alia",3989},{"Sumni",8699}};

    directory.insert(make_pair("Cashna",2233));
    directory["Faltu"]=7685;
    // for(auto ele:directory){
    //     cout<<"The key is:"<<ele.first<<" and the value is "<<ele.second<<endl;
    // }
    // directory["Faltu"]=5;  //this is how we update a value.But we can't have dupicates in maps.

    // directory.insert(make_pair("Cashna",3));  //it will not do anything
    // for(auto ele:directory){
    //     cout<<"The key is:"<<ele.first<<" and the value is "<<ele.second<<endl;
    // }

    //traversing using iterators;
    
    for(auto itr=directory.begin();itr!=directory.end();itr++){
        cout<<itr->first<<"-"<<itr->second<<endl;
    }
   
    //reverse traversal
   
    for(auto itr=directory.rbegin();itr!=directory.rend();itr++){
        cout<<itr->first<<"-"<<itr->second<<endl;
    }


    //instead of using auto,you can first defne itr as map<string,int>::iterator itr;

    map<string,int> :: reverse_iterator itr;
    for(itr=directory.rbegin();itr!=directory.rend();itr++){
        cout<<itr->first<<"-"<<itr->second<<endl;
    }

    //instead of using auto,you can first defne itr as map<string,int>::iterator itr;
    return 0;
}