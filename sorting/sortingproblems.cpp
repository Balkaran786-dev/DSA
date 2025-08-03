// #include<iostream>
// #include<vector>
// using namespace std;
// void sort(vector<int> &v){
//     int n=v.size();
//     for(int i=0;i<n;i++){
//         int index_at_0=-1;
//         for(int j=0;j<n-i;j++){
//             if(v[j]==0){
//                 index_at_0=j;
//                 break;
//             }
//         }
//         if(index_at_0==-1){
//             break;
//         }
//         else{
//          for(int k=index_at_0+1;k<n-i;k++){
//             if(v[k-1]<v[k]){
//                 swap(v[k-1],v[k]);
//             }
//          }
//         }
//     }  //more complicated..idea is that first we find the index of zeroth ele..then we keep swaping from that index till last if larger number is present left to smaller number.
// }
// int main(){
//     vector<int> v(6);
//     v={0,0,0,0,0,5};
//     sort(v);
//     for(int i=0;i<6;i++){
//         cout<<v[i]<<" ";
//     }
//  }



// #include<iostream>
// #include<vector>
// using namespace std;
// void sort(vector<int> &v){
//     int n=v.size();
//     for(int i=0;i<n-1;i++){
//         bool flag=false;
//         for(int j=0;j<n-i-1;j++){
//             if(v[j]==0 && v[j+1]!=0){
//                 swap(v[j],v[j+1]);
//                 flag=true;
//             }
//         }
//         if(!flag){
//             break;
//         }
//     }
// }
// int main(){
//     vector<int> v(6);
//     v={0,4,6,0,0,5};
//     sort(v);
//     for(int i=0;i<6;i++){
//         cout<<v[i]<<" ";
//     }
// }

#include<iostream>
#include<cstring>
using namespace std;
void sort(char fruit[][60],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
           if(strcmp(fruit[min_index],fruit[j])>0){
            min_index=j;
           }
        }
        if(min_index!=i){
            swap(fruit[min_index],fruit[i]);
        }
    }
}
int main(){
    char fruit[][60]={"papaya","lime","watermelon","apple","mango","kiwi"};
    int n=sizeof(fruit)/sizeof(fruit[0]);  //sizeof(fruit) gives 60*6  sizeof(fruit[0]) gives 60 hence n comes out to be 6
    sort(fruit,n);
    for(int i=0;i<n;i++){
        cout<<fruit[i]<<" ";
    }
    return 0;
}