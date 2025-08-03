//1st solution 
// find all permutation ,put them in vector ,sort it  and then return (k-1)th value.




//2nd solution
class Solution {  //o(n) time complexity of calls and o(n) each time for erase function 
//  so it is o(n)*o(n)-. o(n^2) 
// space complexity o(n) for vec and o(n) for storing ans and o(n) for recursion stack.

public:
    int fact(int n){
        if(n==0 || n==1){
            return 1;
        }

        return n*fact(n-1);
    }

    void kth_permutation(string &ans,vector<int> &vec,int n,int k){
        if(n==1){
            ans+=to_string(vec[0]);
            return;
        }
        
        int sub_comb=fact(n-1);  //3!=6
        ans+=to_string(vec[k/sub_comb]);
        vec.erase(vec.begin()+k/sub_comb);
        n-=1;
        k=k%sub_comb;
        kth_permutation(ans,vec,n,k);
    }
    string getPermutation(int n, int k) {
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i]=i+1;
        }
        string ans="";
        kth_permutation(ans,vec,n,k-1);
        return ans;
    }
};



// for the kth smallest permutation
class Solution {
    public:
        int fact(int n) {
            if (n == 0 || n == 1) return 1;
            return n * fact(n - 1);
        }
    
        void kth_permutation(string &ans, string &chars, int n, int k) {
            if (n == 1) {
                ans += chars[0];
                return;
            }
    
            int sub_comb = fact(n - 1);
            int idx = k / sub_comb;
    
            ans += chars[idx];
            chars.erase(chars.begin() + idx);
            kth_permutation(ans, chars, n - 1, k % sub_comb);
        }
    
        string getPermutation(string input, int k) {
            
            int n=input.size();
            bool flag=false;
            char val;
            if(n%2!=0){
                flag=true;
                val=input[n/2];
            }
            int half=(n/2)-1;
            vector<int> freq(26,0);
            for(int i=0;i<half;i++){
                freq[input[i]-'a']++;
            }
           
            int val=1;
            for(int i=0;i<26;i++){
                val*=fact(freq[i]);
            }

            int total_perms = fact(input.size())/val;
    
            if (k < 1 || k > total_perms) {
                return "";  // or throw an exception, or return empty string
            }
            
            string str=input.substr(0,half+1);
            sort(str.begin(),str.end());
            string ans = "";
            kth_permutation(str, input, half, k - 1); // Convert to 0-based
            if(flag) ans.push_back(val);
            string p=ans;
            reverse(ans.begin(),ans.end());
            p+=ans;
            return p;
        }
    };
    