/*
1. We will choose those meetings which will not block other meetings.

2. We will try to give more preference to those meetings that ends earliar and 
   less preference to those that ends late. So, we can arrange them in a order such that 
   the meetings having larger finish time comes after those that finishes earliar. 

3. beacuse,we have arranged them in the increasing order of their finish time,
   so,agr humne ek meeting lagai,toh uske aage vali meeting ka starting time agr
   last hui meeting se bada hua,then only we'll consider it..


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class meeting{
public:
    int start;
    int end;
    int idx;
};
bool cmp(meeting m1,meeting m2){
    return m1.end<m2.end;  //to sort them in ascending order.
}

void print_max_meetings(vector<meeting> &arr){
    sort(arr.begin(),arr.end(),cmp);  
    cout<<arr[0].idx<<" ";  //beacuse room is empty,so,first vali meeting toh definitely hogi.
    meeting last_meeting=arr[0];     //hum last meeting ka track rkhenge so to compare next meeting starting time with last meeting end time
    for(int i=0;i<arr.size();i++){
        if(arr[i].start>last_meeting.end){
            cout<<arr[i].idx<<" ";
            last_meeting=arr[i];
        }
    }
}

int main(){
   int n;
   cin>>n;
   int i=0; //to provide indexes to each of the meetings
   vector<meeting> v;
   while(n--){
    int s,e;
    cin>>s>>e;
    i++;
    meeting m;
    m.start=s;
    m.end=e;
    m.idx=i;
    v.push_back(m);
   }
   print_max_meetings(v);
}