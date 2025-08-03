/* S-total days you require to survive   N-unit of food you can buy each day   M-unit of food you require each day.
 first we calculate total days when we can buy our food.
 these will be equal to total days - sundays that fall in all these days(because we can't buy food on sundays)
 to find total sundays:
 7 days have --- 1 sunday
 1 day have  --- 1/7 sunday
 S days have --- S/7 sundays
 
 x represent total no. of days when we can buy our food.
 x=S-S/7
 
 total food required to survive S days = S*M 
 
 Now,we can calculate how many days do we actually need to buy food.
 
 for N unit of food you require - 1 day
 for 1 unit of food you require - 1/N day.
 for S*M unit of food you require - (S*M)/N
 
 if x>=(S*M)/N ,you can survive and hence print the min days you need to buy food on, but if x<(S*M)/N then you can't survive. because 
 jitne days mein tum pura khanna ekatha kar paoge,utne days toh tumhare paas hai hi nhi.
 
 Greedy approach: hum pehle hi khana ekatha kar lenge taki baad mein koi dikat na aye.
                  jitna stock ho ska utna store kr lenge.
  */

#include<iostream> //S-total days you require to survive  
                   //N-unit of food you can buy each day   
                   //M-unit of food you require each day
using namespace std;
void check_if_survive(int S,int M,int N){
   int total_sundays=S/7; 
   int x=S-total_sundays;
   int total_req_food=S*M;
   int y=total_req_food/N;
   if(total_req_food%N!=0){  //to calculate the seal value
     y+=1;
   }
   
   if(x>=y){
     cout<<"You are able to survive"<<endl;;
     cout<<"Min days you need to buy food:"<<y;
   }
   else{
    cout<<"You are not able to survive";
   }
}
int main(){
    int S,M,N;
    cin>>S>>M>>N;
    check_if_survive(S,M,N);
    return 0;
}