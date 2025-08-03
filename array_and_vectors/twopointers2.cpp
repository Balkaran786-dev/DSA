#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
/*void sorted(vector<int> &v){   // dont forget to put ampersand operator
    int n=v.size();
    int left_ptr=0;
    int right_ptr=n-1;
    while(left_ptr<right_ptr){
        if(v[left_ptr]%2!=0 && v[right_ptr]%2==0){
            int c;
            c=v[right_ptr];
            v[right_ptr]=v[left_ptr];
            v[left_ptr]=c;
            left_ptr++;
            right_ptr--;
        }
        if(v[left_ptr]%2==0){
            left_ptr++;
        }
        if(v[right_ptr]%2!=0){
            right_ptr--;
        }
    }
    return ;
}
int main(){
    int n;
    cout<<"ENTER THE SIZE:";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sorted(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}


   

void squaredSortedvector(vector<int> &v){
    int n=v.size();
    vector<int> ans(n);
    int left_ptr=0;
    int right_ptr=n-1;
    while(left_ptr<=right_ptr){
        if(abs(v[left_ptr])<abs(v[right_ptr])){     // abs is used too find absolute value
            ans.push_back(v[right_ptr]*v[right_ptr]);
            right_ptr--;
        }
        if(abs(v[left_ptr])>abs(v[right_ptr])){
            ans.push_back(v[left_ptr]*v[left_ptr]);
            left_ptr++;
        }
        if(right_ptr==left_ptr){
            ans.push_back(v[left_ptr]*v[left_ptr]);
            left_ptr++;
            right_ptr--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int size;
    cin>>size;
    vector<int> v;
    for(int i=1;i<=size;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    squaredSortedvector(v);
    return 0;
}

   //or
   
#include<iostream>
#include<vector>
using namespace std;
void squaredArray(vector<int> &v){
    int n=v.size();
    for(int j=0;j<n;j++){
    for(int i=0;i<n-1;i++){
        if(v[i]*v[i]>v[i+1]*v[i+1]){
           int c;
           c=v[i+1];
           v[i+1]=v[i];
           v[i]=c;
        }
    }
    }
    for(int i=0;i<n;i++){
        v[i]*=v[i];
    }
}   
int main(){
     vector<int> v={-8,-5,-1,6,10,19};
     squaredArray(v);
     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
     }
    return 0;
}