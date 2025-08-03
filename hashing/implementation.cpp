// #include<iostream>   //using closed addressing.
// #include<list>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class Hashing{
//     vector< list<int> > hashtable;   //at every index,we would have a list. 
//     int buckets;
//     public:
    
//     Hashing(int size){
//         hashtable.resize(size);
//         buckets=size;
//     }
//     int hashvalue(int key){
//         return key%buckets;  //division method
//     }
//     void insertion(int key){
//         int idx=hashvalue(key);
//         hashtable[idx].push_back(key);
//     }
//     list<int>::iterator search_key(int key){
//          int idx=hashvalue(key);
//          return find(hashtable[idx].begin(),hashtable[idx].end(),key);
//     }
//     void deletion(int key){
//         int idx=hashvalue(key);
//         if(search_key(key)!=hashtable[idx].end()){
//             hashtable[idx].erase(search_key(key));
//             cout<<"Key "<<key<<" has been deleted\n";
//         }
//         else{
//             cout<<"Key is not present in the hashtable\n";
//         }
//     }
// };
// int main(){
    // Hashing h(10);
    // h.insertion(682);
    // h.insertion(684);
    // h.insertion(686);
    // h.insertion(284);
    // h.insertion(784);
    // h.deletion(98);
    // h.deletion(784);

// }

#include<bits/stdc++.h>
using namespace std;
class Hashing{
    vector< list<int>> hashtable;
    int buckets;
public:
    Hashing(int size){
        hashtable.resize(size);
        this->buckets=size;
    } 
    int hashvalue(int key){
        return key%buckets;
    }
    void insertion(int value){
        int idx=hashvalue(value);
        hashtable[idx].push_back(value);
        return;
    }
    list<int>::iterator search_key(int key){
        int idx=hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);
    }

    void deletion(int key){
        int idx=hashvalue(key);
        auto itr=search_key(key);
        if(itr!=hashtable[idx].end()){
            hashtable[idx].erase(itr);
            cout<<"key "<<key<<" has been deleted.\n";
        }
        else{
            cout<<"key "<<key<<" has not been deleted.\n";
        }
    }
};
int main(){
    Hashing h(10);
    h.insertion(682);
    h.insertion(684);
    h.insertion(686);
    h.insertion(284);
    h.insertion(784);
    h.deletion(98);
    h.deletion(784);
    return 0;
}
