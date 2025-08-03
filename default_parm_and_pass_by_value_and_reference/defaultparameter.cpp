#include<iostream>
using namespace std;
int add(int x,int y=2,int z=4){
    return x+y+z;
}
int main(){
    int a=54;
    int c=add(a);
    cout<<c<<endl;
    cout<<add(a,2,2)<<endl;
    cout<<add(a,4)<<endl;  /* agar ek parameter humne default 
                           bana diye toh uske baad ke sarre parameter humme default
               karne padenge..otherwise it will throw an error*/
}