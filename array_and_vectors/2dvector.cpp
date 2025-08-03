// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> v1={-1,2,0};
//     // vector<int> v2={4,5};
//     // vector<int> v3={6,7};
//     // vector<vector<int>> V={v1,v2,v3};
    
//     // int 
//     auto it1=find(v1.begin(),v1.end(),2);
//     auto it2=find(v1.begin(),v1.end(),0);
//     v1.erase(it1);
//     v1.erase(it2);
//     for(auto ele:v1){
//         cout<<ele<<" ";
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> vector = { 1, 2, 3, 3, 4, 5 };
    cout << "vector before deleting " << endl;
    for (auto element : vector) {
        cout << element << " ";
    }
 
    // finding the position of the element in the vector
    int valueToBeDeleted = 5;
    auto it = find(vector.begin(), vector.end(),
                   valueToBeDeleted);
    auto it2=find(vector.begin(), vector.end(),
                   4);
    if (it != vector.end()) {
        vector.erase(it);
    }
    if (it2 != vector.end()) {
        vector.erase(it2);
    }
 
    cout << endl
         << "Vector after deleting  valueToBeDeleted "
         << endl;
    for (auto element : vector) {
        cout << element << " ";
    }
    cout << endl;
 
    return 0;
}