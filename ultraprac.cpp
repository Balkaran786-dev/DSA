// #include<iostream>
// #include<vector>
// using namespace std;
// void insertionsort(vector<int> &v){
//     int n=v.size();
//     for(int i=1;i<n;i++){
//         int current=v[i];  
//         int j=i-1;
//         //finding correct position for our current element
//         for( ;j>=0;j--){
//             if(v[j]>current){
//                 v[j+1]=v[j];  // till we are having numbers greater than our current element , keep shifting them right
//             }
//             else{
//                 break;  // when you find a number less than ourcurrent element,we insert our current element after that..
//             }
//         }
//         v[j+1]=current;  // inserting our current elemnt after the number which is smaller than it
//     }
// }
// int main(){
//     vector<int> vec={2,100,7,8,1};
//     insertionsort(vec);
//     for(int i=0;i<vec.size();i++){
//         cout<<vec[i]<<" ";
//     }
// }
#include<iostream>
