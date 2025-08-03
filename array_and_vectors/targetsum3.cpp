#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int size=pow(10,5);
    vector<int> freq(size,0);
    for(int i=0;i<6;i++){
       freq[v[i]]+=1;
    }
    cout<<"enter queries:";
    int q;
    cin>>q;
    while(q>0){
        int queryElement;
        cin>>queryElement;
        cout<<freq[queryElement]<<endl;   /*it will tell us if the number is present or not
                                           and if it is present then how many times..*/
        q--;
    }

    return 0;
}