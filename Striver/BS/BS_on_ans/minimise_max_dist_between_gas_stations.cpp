//

// using prority queue
// o(nlogn + klogn) time
// o(n-1) space

#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){

	// Write your code here.
	int n=arr.size();

	vector<int> how_many(n-1,0);  // how many gas station placed in those gaps
	priority_queue<pair<double,int>> pq;
	for(int i=0;i<n-1;i++){
         pq.push({arr[i+1]-arr[i],i});
	}	

	for(int i=0;i<k;i++){ // placing gas stations one by one
        
		pair<int,int> gap=pq.top();
		pq.pop();
	
		int idx=gap.second;
		pq.push({(double)(arr[idx+1]-arr[idx])/(how_many[idx]+2),idx});
		how_many[idx]++;
	}

	return pq.top().first;
}

