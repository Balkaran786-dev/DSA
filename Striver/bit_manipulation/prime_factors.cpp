//Brute force:-

// finding simply that Is it dividing the number? if yes, 
//then check if it prime,if yes then add it to list otheriwse not

//o(n*sqrt(n)) not always we will be using the prime function only when i completely divides the number.
// so, nearabout itni hogi,


class Solution{
	public:
	bool is_prime(int num){  
	    int cnt=0;
	    for(int i=1;i<=sqrt(num);i++){
	        if(num%i==0){
	            cnt+=1;
	            if(num/i!=i){
	                cnt+=1;
	            }
	        }
	        if(cnt>2) break;
	    }
	    if(cnt==2) return true;
	    else return false;
	}
	
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	     vector<int> prime_fac;
	     
	     for(int i=2;i<N;i++){
	         if(N%i==0){
	             if(is_prime(i)){
	                 prime_fac.push_back(i);
	             }
	         }
	     }
	     return prime_fac;
	}
};


// a little optimisation
//o(srt(n) * sqrt(n))  not exactly but yeah!


class Solution{
	public:
	bool is_prime(int num){
	    int cnt=0;
	    for(int i=1;i<=sqrt(num);i++){
	        if(num%i==0){
	            cnt+=1;
	            if(num/i!=i){
	                cnt+=1;
	            }
	        }
	        if(cnt>2) break;
	    }
	    if(cnt==2) return true;
	    else return false;
	}
	
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	     vector<int> prime_fac;
	     
	     for(int i=2;i<=sqrt(N);i++){ 
	         if(N%i==0){
	             if(is_prime(i)){
	                 prime_fac.push_back(i);
	             }
	             if(N/i!=i){
	                 if(is_prime(N/i)){
	                  prime_fac.push_back(N/i);
	                 }
	             }
	         }
	     }
	     
	     return prime_fac;
	}
};

// using bachpan vala method of lcm,
// if ek number is divisible by 2, keep diving it till it is not divisible by 2,
// esse kya hoga, 
// initially hum number ko 2 se check kiya divisible hai, if yes, we check if it is prime,
// same thing we again check for 4, if it is prime or not.

// if we use the bachpan vala method, the number after being divided by 2 multiple times, it won't be divisible by any 4,6,8..
// becuase im reducing my n, so for loop mein jo n use hua hai voh bhi reduce hota rhega.



	     for(int i=2;i<=N;i++){ // for N=780 , this loop will run for 13 times only,
                                /*
                                2|780  -> yeh right vala hamesha change hota rhega...
                                2|390
                                3|195
                                5|65
                               13|13
                                 |1   */       
	         if(N%i==0){
	            prime_fac.push_back(i);  // yeh sidha hi dalega kyunki, yeh divide hi tab krega jab yeh prime hoga,2,3,4 krega ni,5 and so on..
	            while(N%i==0){
	                N/=i;
	            }
	         }
	     }
	     
	     return prime_fac;

         // but for prime number N,
         // it will run N times , beacuse it won't get reduced.


         // can we make the loop run till sqrt(N)?
         // yess. 

         // but edge cse:
         // if N is prime, then last mein humme, usse add krne hoga, so hum hamesha add nhi krnge last mein N, only when N!=1,
         // because take example of N=16, usmme last mein N 1 reh jayega and last mein 1 toh add nhi kr skte.
class Solution{
	public:

	vector<int>AllPrimeFactors(int N) {
	    // Code here
	     vector<int> prime_fac;
	     
	     for(int i=2;i<=sqrt(N);i++){
	         if(N%i==0){
	            prime_fac.push_back(i);
	            while(N%i==0){
	                N/=i;
	            }
	         }
	     }
	     
	     if(N!=1){
	         prime_fac.push_back(N);
	     }
	     
	     return prime_fac;
	}
};


	