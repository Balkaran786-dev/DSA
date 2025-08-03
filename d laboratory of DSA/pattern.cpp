#include<bits/stdc++.h>  
using namespace std;
void print_pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i-1;j>=1;j--){
            cout<<" ";
        }
        int k=i+1;
        if(i!=0){
           for(int l=1;l<=((2*i+1)/2)+1;l++){
            cout<<k;
            k++;
           }
            k-=2;
        }
        for(int m=k;m>=i+1;m--){
            cout<<m;
        }
        cout<<endl;
    }
}
int main(){
    int rows;
    cin>>rows;
    print_pattern(rows);
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";   
    return 0;
}