//explanation given in copy..

bool distribute(vector<int>& arr,int mid, int n, int m){
    int currSum=0;
    int stureq=1;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        else if(arr[i]+currSum>mid){
            currSum=arr[i];
            stureq++;
            if(stureq>m) return false;
        }
        else{
            currSum+=arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;

    int sum=0;
    int biggest=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        biggest=max(biggest,arr[i]);
    }
    int lo=biggest;
    int hi=sum;
    
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(distribute(arr,mid,n,m)){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    
    return lo; //You can't return hi, only lo will be present at your ans..
}