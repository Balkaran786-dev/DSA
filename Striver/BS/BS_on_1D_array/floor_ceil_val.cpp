//floor value:- The floor of x is the largest element in the 
//array which is smaller than or equal to x( i.e. largest element in the array <= x).

//ceil value:- The ceiling of x is the smallest element in the array greater 
//than or equal to x( i.e. smallest element in the array >= x).
int find(vector<int> &a,int x,int n,bool flag){
	int lo=0;
	int hi=n-1;
	int ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(a[mid]==x){
			ans=x;
			return ans;
		}
		else if(a[mid]>x){
			if(!flag){
				ans=a[mid];
			}
			hi=mid-1;
		}
		else if(a[mid]<x){
			if(flag){
				ans=a[mid];
			}
			lo=mid+1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int floor=find(a,x,n,true);
	int ceil;
	if(floor==x){
		return {x,x};
	}
	else{
		ceil=find(a,x,n,false);
	}
	return {floor, ceil};
}