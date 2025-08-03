#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v(7);
    for(int i=0;i<7;i++){
        cin>>v[i];
    }
              //to find last occurence of x
   /* int x;
    cin>>x;
   int occurence=-1;
    for(int i=0;i<6;i++){
        if(v[i]==x){
            occurence=i;
        }
    }              // you can do it by traversing from the end of vector
    cout<<occurence<<endl;
    
    int p;
    cout<<"Enter value of p:";
    cin>>p;   //to find no.of occurence of p.

    int occurence=0;
    for(int i=0;i<7;i++){
        if(v[i]==p){
            occurence+=1;
        }
    }
    cout<<occurence<<endl;

    int q;
    cout<<"Enter q:";
    cin>>q;  //To find number of elements strictly greater than q
    int numberofelements=0;
    for(int i=0;i<7;i++){
        if (v[i]>q){
           numberofelements++; 
        }
    }
    cout<<"Number of elements strictly greater than q: "<<numberofelements;

    int i=1;
    string result="sorted";
    while(i<v.size()){
        if(v[i]>v[i-1]){
            i++;
        }
        else{
            result="unsorted";
            break;
        }
    }
    cout<<result<<endl;*/


    int evensum=0;
    int oddsum=0;
    for(int i=0;i<7;i+=2){
        evensum+=v[i];
    }
    for(int i=1;i<7;i+=2){
        oddsum+=v[i];
    }
    cout<<"DIFFERENCE:"<<evensum-oddsum;
    return 0;
}