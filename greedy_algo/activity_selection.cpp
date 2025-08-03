/*

similar to meeting vali problem
1. main intitution: agr kise bhut badi activity ke vajah se 
we are not able to perform 2-3 small duration vali activites,so skipping the larger
activity for the performing the smaller activities is a better option because 
we need to maximise our no. of activities.


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class activity{
public:
    int start;
    int end;
};
bool cmp(activity a1,activity a2){
    return a1.end<a2.end;   //going to arrange the elements on the basis of ending time.
}
int max_activities(vector<activity> v){
    sort(v.begin(),v.end(),cmp);
    int count=1;  //because jo pehli activity hogi voh toh definitely krenge hi krenge.
    activity last_activity=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i].start>last_activity.end){
            count++;
            last_activity=v[i];
        }
    }

    return count;
}
int main(){
   int n;
   cin>>n;
   vector<activity> activities_list;
   while(n--){
    int s,e;
    cin>>s>>e;
    activity a;
    a.start=s;
    a.end=e;
    activities_list.push_back(a);
   }
   cout<<max_activities(activities_list);
    return 0;
}