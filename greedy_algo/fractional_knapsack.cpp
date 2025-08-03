//humara greedy choice kya hai?
//humme max se max profit min se min weight par lena hoga,taki aage bhi kuch weight hum le paye..
//hum yeh bhi nhi kar skte ki voh weight sabse pehle uthaye jiska profit sabse jada ho,kya pata uska weight bhi bhut jada ho
//hum yeh bhi nhi kar skte ki voh weight sabse pehle uthaye jiska weight sabse kam ho,kya pata uska profit bhi bhut kam ho
//so,we need to consider both the weight and profit factor combinely,
//goal-> maximise the profit and minimise the weight
// profit/weight   ess expression ki value jisske liye sabse jada hogi,usko sabse pehle consider krenge..
// weight ko ya toh pura lenge, ya uska kuch fraction lenge.
// fraction needed= weight needed in knapsack/total weight.  fer itna fraction hi hum profit lenge...


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;  //time complexity -o(nlogn)
                      //space complexity -o(the space covered while doing sorting).
//static_cast
//sort function in c++ STL;

class item{
public:
    int profit;
    int weight;

};

bool cmp(item i1,item i2){   //comparator function for our sort function
    double f1=static_cast<double> (i1.profit)/(i1.weight);
    double f2=static_cast<double> (i2.profit)/(i2.weight);
    return f1>f2;
}
double fractional(int capacity,vector<item> &items){
         double total_profit=0;
         sort(items.begin(),items.end(),cmp); 
         //now,the items are arranged in a manner such that the item having the highest ratio of profit/weight comes first..
         for(const auto &i:items){
            if(i.weight<=capacity){
                total_profit+=i.profit;
                capacity-=i.weight;
            }
            else{
                double fraction=static_cast<double> (capacity)/(i.weight);
                total_profit+=i.profit*fraction;
                capacity=0;  //kyunki uski bacchi hui space toh eske fraction weight ne hi cover krli.so left capacity becomes zero.
            }
         }
         return total_profit; 
}

int main(){
    int n,w;
    cout<<"Total items:";
    cin>>n;
    cout<<"Total capacity of knapsack:";
    cin>>w;
    vector<item> items;
    for(int i=0;i<n;i++){
        int prof,weigh;
        cin>>prof>>weigh;
        item it;
        it.profit=prof;
        it.weight=weigh;
        items.push_back(it);
    }
    cout<<fractional(w,items);
    return 0;
}