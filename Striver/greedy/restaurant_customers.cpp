//
#include <bits/stdc++.h> 
int maxCustomers(vector<int> &arrival, vector<int> &leaving)
{
	// Write your code here.
	int n=arrival.size();
	sort(arrival.begin(),arrival.end());
	sort(leaving.begin(),leaving.end());
    
	int cnt=0;
	int max_cnt=0;
	int p1=0,p2=0;
    while(p1<n){
        if(arrival[p1]<leaving[p2]){
			p1++;
			cnt++;
		}
		else{
			p2++;
			cnt--;
		}
		max_cnt=max(max_cnt,cnt);
	} 
	return max_cnt;
}