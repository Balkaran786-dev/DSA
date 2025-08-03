/*
if we have a bigger interval that is starting early and ending late,we need to evaluate it later
otherwise if we sort our intervals on the basis of start time , it would come pehle and usko consider krliya,
then humme kafi saare short intervals ke elements ko remove karna pdega uski aadh mein.but we need to remove min ele.

*/


#include<iostream>  //o(nlogn)-time complexity  o(sort vali space)-space complexity  
                    //while sorting,we use some variation of quick sort,so most probably we do o(logn) calls.
#include<vector>
#include<algorithm>
using namespace std;

class interval{
public:
       int start;
       int end;
};

bool cmp(interval i1,interval i2){
     return i1.end<i2.end;
}
int min_intervals_removal(vector<interval> &intervals){
    int interval_to_remove=0;
    sort(intervals.begin(),intervals.end(),cmp);
    interval last_interval=intervals[0];
    for(int i=1;i<intervals.size();i++){
         if(intervals[i].start<last_interval.end){
             interval_to_remove++;
         }
         else{
            last_interval=intervals[i];
         }
    }
    
    return interval_to_remove;
}
int main(){
    int n;
    cin>>n;
    vector<interval> intervals;
    while(n--){
        int s,e;
        cin>>s>>e;
        interval i;
        i.start=s;
        i.end=e;
        intervals.push_back(i);
    }
    cout<<min_intervals_removal(intervals);
    return 0;
}

