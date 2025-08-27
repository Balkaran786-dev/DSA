// two pointer approach.
// time o(n1+n2)  space o(1);

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int index=k-1;
        int cnt=-1;
        int n1=a.size();
        int n2=b.size();
        int ele=-1;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                cnt++;
                if(cnt==index){
                    ele=a[i];
                    break;
                }
                i++;
            }
            else{
                cnt++;
                if(cnt==index){
                    ele=b[j];
                    break;
                }
                j++;
            }
        }
        while(ele==-1 && i<n1){
                cnt++;
                if(cnt==index){
                    ele=a[i];
                    break;
                }
                i++;
        }
        while(ele==-1 && j<n2){
                cnt++;
                if(cnt==index){
                    ele=b[j];
                    break;
                }
                j++;
        }
        return ele;
    }
};


// o(log(min(n1,n2))) time   o(1) space

// explained in contest copy...


int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Write your code here
    
	if(n1>n2){
		return kthElement(b,a,n2,n1,k);
	}

	int n=n1+n2;
	int left=k;
	int lo=max(0,k-n2);  // explained why in contest copy...
	int hi=min(n1,k);
	
	while(lo<=hi){
		int mid1=(lo+hi)>>1;
		int mid2=left-mid1;
		int l1=-1;
		int l2=-1;
		int r1=5001;
		int r2=5001;
		if(mid1<n1) r1=a[mid1];
		if(mid1!=0) l1=a[mid1-1];
		if(mid2<n2) r2=b[mid2];
		if(mid2!=0) l2=b[mid2-1];
		
		if(l1<=r2 && l2<=r1){
			return max(l1,l2);
		}
		else if(l1>r2) hi=mid1-1;
		else if(l2>r1) lo=mid1+1;
	}
	return -1;
}