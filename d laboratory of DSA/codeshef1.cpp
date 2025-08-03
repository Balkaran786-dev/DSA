 #include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
    int T;
    cin>>T;
    while(T--){
      int N,X;  //N -> number of items X->minimum freshness
      
      cin>>N;
      
      cin>>X;
      int A[N],B[N];
      for(int i=0;i<N;i++){
          cin>>A[i];
      }
      for(int i=0;i<N;i++){
          cin>>B[i];
      }
      int total_cost=0;
      for(int i=0;i<N;i++){
          if(A[i]>=X) total_cost+=B[i];
      }
      cout<<total_cost;
    }
cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";
}
