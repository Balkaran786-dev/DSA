// SPF-> smallest prime factor
// using seive:-

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> SPF(N+1,-1);
        
        for(int i=2;i<=N;i++){ //o(N)
            SPF[i]=i;
        }
        
        for(int i=2;i<=sqrt(N);i++){  //o(Nlog(log(n)))
            if(SPF[i]==i){
                for(int j=i*i;j<=N;j+=i){
                    if(SPF[j]==j){
                        SPF[j]=i;
                    }
                }
            }
        }
        
        vector<int> ans;
        while(N!=1){        //log(n)
            int spf=SPF[N];
            ans.push_back(spf);
            N/=spf;
        }
        return ans;
    }
    
};

