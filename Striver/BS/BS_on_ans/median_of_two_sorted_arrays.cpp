//Bruteforce time complexity-o(n) space o(n)
// since you r given with two sorted arrays, merge them into a third sorted array.
// now, if n=n1+n2, (n)%2==1  that is odd, return arr3[n/2];
// else return (double)(arr3[n/2]+arr3[(n/2)-1])/2.0   ;




//Better we really don't need to know any other ele in the merged array but just
// the element at n/2 idx  and (n/2)-1 idx...we just need to find this only.
// we take two pointers at starting index of both the arrays.
// we keep inc cnt which is initilised as -1 along we compare which ele is smaller,
// if at any time, cnt == (n/2)-1 , ele1=a[i] or b[j] jo bhi smaller hoga voh toh hume compare krte hue pta lgega.
// if at any time, cnt == n/2 , ele2=a[i] or b[j]and break..
double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n1=a.size();
	int n2=b.size();
	int n=n1+n2;
	int cnt=-1;
	int ind2=n/2;
	int ind1=ind2-1;
	int ele1=-1,ele2=-1;
	int i=0,j=0;
	while(i<n1 && j<n2){
		if(a[i]<b[j]){
			cnt++;
			if(cnt==ind1) ele1=a[i];
			else if(cnt==ind2){
				ele2=a[i];
				break;
			}
			i++;
		}
		else{
			cnt++;
			if(cnt==ind1) ele1=b[j];
			else if(cnt==ind2){
				ele2=b[j];
				break;
			}
			j++;
		}
	}

	while(ele2==-1 && i<n1){
		    cnt++;
			if(cnt==ind1) ele1=a[i];
			else if(cnt==ind2){
				ele2=a[i];
				break;
			}
			i++;
	}
	while(ele2==-1 && j<n2){
		    cnt++;
			if(cnt==ind1) ele1=b[j];
			else if(cnt==ind2){
				ele2=b[j];
				break;
			}
			j++;
	}

	if(n%2==1){
		return ele2;
	}

	return (double)((double)ele1+(double)ele2)/2.0;
}


/// binary search approach:-
// explained in contest question copy...

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n1=a.size();
	int n2=b.size();
	if(n1>n2){
		return median(b,a);
	}

	int n=n1+n2;
	int left=(n1+n2+1)/2;
	int lo=0;
	int hi=n1;
	while(lo<=hi){
		int mid1=(lo+hi)>>1;
		int mid2=left-mid1;
		int l1=INT_MIN;
		int l2=INT_MIN;
		int r1=INT_MAX;
		int r2=INT_MAX;
		if(mid1<n1) r1=a[mid1];
		if(mid1!=0) l1=a[mid1-1];
		if(mid2<n2) r2=b[mid2];
		if(mid2!=0) l2=b[mid2-1];
		
		if(l1<=r2 && l2<=r1){
			if(n%2==1){
				return max(l1,l2);
			}
			else{
				return (max(l1,l2)+min(r1,r2))/2.0;
			}
		}
		else if(l1>r2) hi=mid1-1;
		else if(l2>r1) lo=mid1+1;
	}
	return -1;
}

