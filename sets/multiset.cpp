#include<iostream>
#include<set>
using namespace std;
//in multiset,find() gives us lowerbound whereas in simple set,find() gives us the iterator to that element,
//otherwise,it return end iterator,if we defrence this end iterator,it gives us some garbage value which seems as an integer sometimes.
int main(){
   multiset<int> ms;
   ms.insert(1);
   ms.insert(2);
   ms.insert(3);
   ms.insert(2);
   for(auto ele:ms){
    cout<<ele<<" ";
   }cout<<endl;
}