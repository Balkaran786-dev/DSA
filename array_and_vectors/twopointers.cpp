// #include<iostream>
// #include<vector>
// using namespace std;
// /*void sorted0and1(vector<int> &v){  //dont forget to put ampersand opertaor 
//     int zero_count=0;
//     for(int i=0;i<v.size();i++){
//         if(v[i]==0){
//             zero_count+=1;
//         }
//     }
//     for(int i=0;i<v.size();i++){
//         if(i<zero_count){
//             v[i]=0;
//         }
//         else{
//             v[i]=1;
//         }
//     }
// }
// int main(){
//     int n;
//     cout<<"enter the size:";
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cout<<"v("<<i<<"):";
//         cin>>v[i];
//     }
//     sorted0and1(v);
//     for(int i=0;i<n;i++){
//         cout<<"v("<<i<<")";
//         cout<<v[i]<<endl;
//     }
//     return 0;
// }*/

//    // AGAR SAMAJH NA AYE TOH DRY RUN KARLO..AA JAYEGA

// void sorted0and1(vector<int> &v){
//     int n=v.size();
//     int left_ptr=0;
//     int right_ptr=n-1;
//     while(left_ptr<right_ptr){
//         if(v[left_ptr]==1 && v[right_ptr]==0){
//             v[left_ptr++]=0;
//             v[right_ptr--]=1;
//         }
//         if(v[left_ptr]==0){
//             left_ptr++;
//         }
//         if(v[right_ptr]==1){
//             right_ptr--;
//         }
//     }
//     return;
// }
// int main(){
//     int n;
//     cout<<"enter the size:";
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }

//     sorted0and1(v);
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
}