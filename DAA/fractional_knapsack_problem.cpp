#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;  //time complexity -o(nlogn)
                      //space complexity -o(the space covered while doing sorting).

class item{
public:
    int profit;
    int weight;

};

bool cmp(item i1,item i2){   //comparator function for our sort function
    double f1=((double) i1.profit)/(i1.weight);
    double f2=((double) i2.profit)/(i2.weight);
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