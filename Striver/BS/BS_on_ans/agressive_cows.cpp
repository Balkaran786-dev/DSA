// Brute force linear search...
// start hum krenge difference of last and first spot that will be the maximium diff
// end krenge 0 pe,
// jo bhi diff pehla aisa mila jispe saare cows place ho gaye return it, it will be the maximum vakue of the distance between two student...






//Binary search,,,,   time complexity -o(nlogn + log(hi)*n)..

// yahan hum on the basis of cows placed pe eliminate krenge,
// if cows placed are == or greater than given, we tend to move right, because agr greater hai, that means the distnace is smaller, and if = hai thwn also we tend to incraese the dist
// if cows placed are lesse than given, we tend to move left, because age lesse hai, means hummne distnace jada hi maximise krdiya...
bool placed(vector<int> &stalls,int mid,int n, int k){
    int cows=1;
    int last_placed=0;   //idx
    for(int i=1;i<n;i++){
        if(stalls[i]-stalls[last_placed]>=mid){
            last_placed=i;
            cows++;
            if(cows>=k) return true;
        }
    }
    
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();   
    sort(stalls.begin(),stalls.end());  //nlogn
    int lo=0;
    int hi=stalls[n-1]-stalls[0];

    while(lo<=hi){          //log(hi)*o(n)..
        int mid=lo+(hi-lo)/2;
        if(placed(stalls,mid,n,k)){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return hi;  // is baar hi will be at our ans rethink the case when lo==hi, then what happens is both will be at our ans but lo will be made equal to mid+1, because we tend to maximise the dist
}