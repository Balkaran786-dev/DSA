//bruteforce linear sercah:
// start from min day to max day,
// at which ever day, you r able to make bouquets -> return it, that is min.



// optimal
// range from min day to max day,
// if(we are able to make bouquets at some mid,we tend to move left) -> we need to minimise the days required
// if(we are able to make more number of bouquets also at some mid, we tend to move left) -> we need to minimise the days..
// if(we are not able to make bouquets at some mid,we tend to move right) -> that will increase the number of flowers bloom and also inc our chances to make bouquets..



/*
int count=0;
        int bouquets=0;
        
        for(int i=0;i<n;i++){
            if(v[i]<=mid){
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        
        if(bouquets<m) return false;
        return true;*/

// can also use the above logic...

class Solution {
public:
    bool make_it(vector<int>& v, int m, int k,int n,int mid){
        int count=0;
        int bouquets=0;
        
        for(int i=0;i<n;i++){
            if(v[i]<=mid){
                count++;
            }
            else{
                bouquets+=(count/k);
                count=0;
            }
        }
        bouquets+=(count/k);
        if(bouquets<m) return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long value=1LL*m*k;
        int n=bloomDay.size();
        if(value>n) return -1;
        int lo=INT_MAX;
        int hi=INT_MIN;
        for(int i=0;i<n;i++){
          hi=max(hi,bloomDay[i]);
          lo=min(lo,bloomDay[i]);
        }

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(make_it(bloomDay,m,k,n,mid)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};