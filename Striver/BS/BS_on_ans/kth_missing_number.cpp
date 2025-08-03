// Array is sorted.
// only positive integers presnt..
// we can think that k can also be the ans if forex:- k=5  arr=7,10,67,78
// here ans=k=5, because no number was lesser than k,
// if arr was like 4,7,9,10  k=5;
// ans won't be 5, beacuse 4 will take place in between this, 6 will be the ans,,
// so, whenever there is a number lesser than k, we inc the k,
// if the number is greater than k, we straight away return k as ans..


class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int n=arr.size();
            for(int i=0;i<n;i++){
                if(arr[i]<=k){
                    k++;
                }
                else{
                    break;
                }
            }
            return k;
        }
    };




// time complexity o(logn)
// here we we applying bs on how many integers are missing on that index.
// for ex:-
// 2,3,4,7,11; k=5
// ideally there should have been 1,2,3,4,5 if no number was missing
// at index 0, 2-1=1 number missing, index 1, 3-2=1 number missing
// missing  array=1,1,1,3,6(denating how manynumbers are missing at before i at index i),
// we apply bs to find k on this missing array,
// always our hi pointer(yehi kaam ayega) will be on a value less than k after the loop,
// then we do ...return arr[hi]+(k-(arr[hi]-hi-1))  or hi+1+k or lo+k;


// one edge case, if k<arr[lo]  , iss case mein hamara hi -1 index pe aa jayega, toh we can't use arr[hi]+(k-(arr[hi]-hi-1)) 
// so, if k<arr[lo] ,retunr k..

class Solution {
        public:
            int findKthPositive(vector<int>& arr, int k) {
                int n=arr.size();
                int lo=0,hi=n-1;
                if(k<arr[0]) return k;
                while(lo<=hi){
                    int mid=lo+(hi-lo)/2;
                    if((arr[mid]-(mid+1))>=k){
                        hi=mid-1;
                    }
                    else{
                        lo=mid+1;
                    }
                }
                return arr[hi]+(k-(arr[hi]-hi-1));
            }
};