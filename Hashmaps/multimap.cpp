// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     multimap<string,int> directory;
//     directory.insert(make_pair("Balkaran",463435));
//     directory.insert(make_pair("urvi",123328));
//     directory.insert(make_pair("urvi",409891));
//     //directory["Tarun"]=54637;   not allowed...
//     for(auto ele:directory){
//         cout<<ele.first<<"-"<<ele.second<<endl;
//     }
//     cout<<directory.count("urvi");
//     return 0;
// }

//use of equal_range member function
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    // initialize container
    multimap<int, int> mp;
    // insert elements in random order
    mp.insert(make_pair( 2, 30 ));
    mp.insert(make_pair( 1, 40 ));
    mp.insert(make_pair( 3, 60 ));
    mp.insert(make_pair( 1, 20 ));
    mp.insert(make_pair( 5, 50 ));
 
    // Stores the range of key 1
    auto it = mp.equal_range(1);  //gives pair of two iterators. first iterator points to first pair with k key and 
                                  //second points to the position after last pair with k key.
 
    cout << "The multimap elements of key 1 is : \n";
    cout << "KEY\tELEMENT\n";
 
    // Prints all the elements of key 1
    for (auto itr = it.first; itr != it.second; ++itr) {
        cout << itr->first
             << '\t' << itr->second << '\n';
    }
   //  If there are no matches with key K, the range returned is of length 0 with both 
   //  iterators pointing to the first element that has a key considered to go after k
   //hence loop won't work even a single time as both iterators will be poiting to same position.
    return 0;
}