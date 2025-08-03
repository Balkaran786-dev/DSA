// Brute force 
// humme nikalna hai ki voh ek ghnate mein kitne banana ghaye,
// linear search, jo bhi pehle speed mili jispe hum within hrs saare banana kha paye , that will be our ans,
// where do we need to start, min of all()  noo......
// beacuse may be our hrs given is too high and we need to minimise our k,
// so start from 1 and end at max of all()  , 
///   imp --->  max of all() se jada pe bhi if we take , then it will take same number of hrs as we took at maxofall().


//Binary serach...

// lo=1 and hi=max of all() 
// jaise book allocation ke case mein we eliminate one half on the bases of stu req.
// here , we do that on the bases of number of hrs req,
// if(number of hrs<= given) move to left
// else move to right...

bool finish_eat(vector<int>& piles,int mid,int h,int n){
       int total_hrs=0;
        for(int i=0;i<n;i++){
           total_hrs+=ceil((double)piles[i]/(double)mid);
           if(total_hrs>h) return false;
        }
        return true;
}

int minimumRateToEatBananas(vector<int> piles, int h) {
    // Write Your Code Here
    int n=piles.size();
        int lo=1;
        int hi=-1;
        for(int i=0;i<n;i++){
            // lo=min(lo,piles[i]);
            hi=max(hi,piles[i]);
        }

        while(lo<=hi){
            int mid=(hi+lo)/2;
            if(finish_eat(piles,mid,h,n)){
                
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
}