// take lo=1 and hi=m

// take mid and find multiply it n times, if while doing this at any iteration, you got the value > m return 2
// return 0 if this value = m otherwise return 1 if value < m,

// if you got 2, that means you can neglect the right half, hence hi=mid-1;
// if you git 0 return mid
// if u got 1, lo=mid+1;


class Solution {
  public:
    /*
    return 2 if >m
    return 0 if ==m
    return 1 if <m
    */
    int func(int mid,int n,int m){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=mid;
            if(ans>m) return 2;
        }
        if(ans==m) return 0;
        return 1;
    }
    int nthRoot(int n, int m) {
        int lo=1;
        int hi=m;  // may be they can ask 1th root of m, so in that case m will be the ans.
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int midN=func(mid,n,m);
            if(midN==0) return mid;
            
            else if(midN==2) hi=mid-1;
            
            else lo=mid+1;
        }
        
        return -1;
    }
};

