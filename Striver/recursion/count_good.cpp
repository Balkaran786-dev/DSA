// from 0 to 9,only 5 even numbers and 4 primes are present
class Solution {
public:
    int M = 1e9+7; 
    long pow(long x,long n){
        if(n==0) return 1;
        long temp=pow(x,n/2);

        if(n%2==0){
            return (temp*temp)%M;
        }
        else{
            return (x*temp*temp)%M;
        }
    }
    int countGoodNumbers(long long n) {
        long even=(n+1)/2;   //always itne hi honge 
        long odd=n/2;
        long first=pow(5,even)%M;
        long second=pow(4,odd)%M;
        return (int)((first*second)%M);
    }
};