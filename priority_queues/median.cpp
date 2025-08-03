#include<iostream>
#include<queue>
using namespace std;
class median_finder{

       priority_queue<int> maxpq;  //for storing the lower half.
       priority_queue<int,vector<int>,greater<int>> minpq; //for storing the greater half

       public:
       void add(int num){
          if(maxpq.empty() || num<maxpq.top()){
            maxpq.push(num);
          }
          else{
            minpq.push(num);
          }

          //rebalancing the pq
          if(minpq.size()>maxpq.size()){  //minpq becomes greater than  maxpq,we add its element to maxoq 
            maxpq.push(minpq.top());
            minpq.pop();
          }
          else if(maxpq.size()-minpq.size()>1){ //if maxpq has more 2 elements than than minpq,add its one element to minpq.
          //means maxpq ek element zada le skti hain,but usse jada nhi.lekin minpq toh hamesha either equal to or lesser than maxpq.
            minpq.push(maxpq.top());
            maxpq.pop();
          }
       }

       float find_median(){
          if(maxpq.size()==minpq.size()){
            return (maxpq.top()+minpq.top())/2.0;
          }
          else{  //matlab maxpq mein ek element jada hoga
            return maxpq.top();
          }
       }
};
int main(){
    median_finder* md=new median_finder;
    md->add(8);
    md->add(9);
    md->add(2);
    md->add(5);
    md->add(1);
    md->add(10);
    cout<<md->find_median();
    return 0;
}