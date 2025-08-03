// o(NlogN) time

class Solution {
  public:
    int merge(vector<int> &arr,int l,int mid,int r){   
        
        int cnt=0;

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
        int k=l;  // to insert the element of array a and b in increasing order in arr..
        while(i<an && j<bn){
          if(a[i]<=b[j]){
            arr[k++]=a[i++];
          }
          else{
            cnt += (an - i);   // yeh saare elements must be greater than than b[j]..so all can be considered as inversions.
            arr[k++]=b[j++];
          }
        }
        
        while(i<an) arr[k++]=a[i++];  //if b is fully filled in arr,we need to just fill leftover a elements in arr
        while(j<bn) arr[k++]=b[j++];  //if a is fully filled in arr,we need to just fill leftover b elements in arr
        return cnt;
    }

    int mergesort(vector<int>&arr,int l,int r){
        int cnt=0;
        if(l>=r) return cnt;;
        int mid=(l+r)/2;
        cnt+=mergesort(arr,l,mid);  
        cnt+=mergesort(arr,mid+1,r);  //both split the array into two halves.
        cnt+=merge(arr,l,mid,r);  //merge the sorted arrays.
        
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        return mergesort(arr,0,arr.size()-1);
    }
};

