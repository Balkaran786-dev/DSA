//intuition in copy

// there in count inversion, if an elemnet in 'a' array is greater than an element in 'b' array
// you can say all the remaining elements in the array 'a' will be forming an inversion with that element in b.

// but here you can't be sure about it, so for an element in a, you travel in b till you get an element not satisfying  the condition,
// So, you do cnt+=(right-(mid+1));
// then for second ele in a, your right will still be there where it has been when the cond
// for the first ele has unsatisfied, because we know, usse peche vale agr 1st ele ke liye ho gye, then second ke liye kiye bhi obviously ho jayenge.

// time -> o(2NlogN)
// space -> o(N) used while merging arrays.


class Solution {
public:
    void merge(vector<int> &arr,int l,int mid,int r){   

        int an=mid-l+1;
        int bn=r-mid;
        int a[an],b[bn];  
        for(int i=0;i<an;i++){
           a[i]=arr[l+i];
        }
        for(int j=0;j<bn;j++){
           b[j]=arr[mid+1+j];
        }

        int i=0;
        int j=0;
        int k=l;  
        while(i<an && j<bn){
          if(a[i]<=b[j]){
            arr[k++]=a[i++];
          }
          else{
            arr[k++]=b[j++];
          }
        }
        while(i<an) arr[k++]=a[i++];  
        while(j<bn) arr[k++]=b[j++];  
    }

    int countPairs(vector<int> &arr,int l,int mid,int r){
        int cnt=0;
        int right=mid+1;
        for(int i=l;i<=mid;i++){
            while(right<=r && arr[i]>2*(long long)arr[right]) right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }

    int mergesort(vector<int>&arr,int l,int r){
        int cnt=0;
        if(l>=r) return cnt;;
        int mid=(l+r)/2;
        cnt+=mergesort(arr,l,mid);  
        cnt+=mergesort(arr,mid+1,r);  //both split the array into two halves.
        cnt+=countPairs(arr,l,mid,r); 
        merge(arr,l,mid,r);  //merge the sorted arrays.
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};