//most optimised.
// other approaches are given in copy
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1,1);
        for(int i=2;i<=sqrt(n);i++){
            if(primes[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }
        
        int count=0;
        for(int i=2;i<n;i++){
            if(primes[i]==1) count++;
        }

        return count;
    }
};



// count primes from L to R
// similar to above question just n ki jagah R and last loop mein run from L to R
// In case of query based question
// calculate prefix of the seive array,
// then find arr[R]-arr[L-1];


class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
        vector<int> primes(R+1,1);
        for(int i=2;i<=sqrt(R);i++){
            if(primes[i]==1){
                for(int j=i*i;j<=R;j+=i){
                    primes[j]=0;
                }
            }
        }
        primes[1]=0;
        int count=0;
        for(int i=L;i<=R;i++){
            if(primes[i]==1) count++;
        }

        return count;
    }
};