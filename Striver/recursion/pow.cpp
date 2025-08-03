//recursive
class Solution {
public:
    double get_pow(double num,long long n){
        if(n==0) return 1;
        else if(n%2==0){
            double ans=get_pow(num,n/2);
            return ans*ans;
        }
        else{
            double ans=get_pow(num,(n-1)/2);
            return ans*ans*num;
        }
    }
    double myPow(double x, int n) {
         ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        long long nn=abs(n);
        double res=get_pow(x,nn);
        if(n>=0){
            return res;
        }
        else{
            return 1/res;
        }
    }
};