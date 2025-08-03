#include<iostream>
#include<vector>
#include<algorithm>   // to work with reverse operation,we use it
using namespace std;
int main()
{                     // reverse the array by k steps
    vector<int> v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    int k;
    cout<<"Enter the value of k:";
    cin>>k;
    k=k%5;

    for(int i=1;i<=k;i++){
        v.insert(v.begin(),v[4]);
        v.pop_back();  
    }
    cout<<"ansarray: "
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }   
    
   // OR

  /* vector<int> v(5);
   for(int i=0;i<5;i++){
     cin>>v[i];
   }
   int k=2;
   k=k%v.size();
   reverse(v.begin(),v.end());
   reverse(v.begin(),v.begin()+k);
   reverse(v.begin()+k,v.end());

   for(int i=0;i<5;i++){
    cout<<v[i]<<" ";
   }
        
        //OR

   /*int array[]={1,2,3,4,5};
   int k=5;
   k=k%5;
   int revarray[5];
   for(int i=5-k,j=0 ;i<5,j<k ;i++,j++){
       revarray[j]=array[i];
   }
   for(int i=0,j=k ;i<5-k,j<5 ;i++,j++){
       revarray[j]=array[i];
   }
   
   for(int i=0;i<5;i++){
      cout<<revarray[i]<<" ";
   }*/
    return 0;
}