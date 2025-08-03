#include<iostream>
using namespace std;
void towerOfHanoi(int n, char from, char to,char by){
    if(n==0){
      return;
    }
    towerOfHanoi(n - 1, from, by, to);
    cout<<n<<" disk : "<< from <<" -> "<<to<<endl;
    towerOfHanoi(n - 1, by, to, from);
}
int main(){
   int n;
   cout<<"Enter the number of disks:- "<<endl;
   cin>>n;
   towerOfHanoi(n, 'a', 'c', 'b');
    return 0;
}


