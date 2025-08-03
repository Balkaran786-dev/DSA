// if size of s == k , hum sabhi charcters ko ek ek krdenge,hence true;
// if size of s < k, hume puri k strings bnana ke liye characters hi nhi milenge,hence false;
// we will be storing all the characters in hash array, 
// we will check if no_of_odd frequencies are > k, we can't make k palindromes, hence return false.

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k) return true;
        if(n<k) return false;

        vector<int> hash_array(26,0);
        for(int i=0;i<n;i++){
            hash_array[s[i]-'a']++;
        }
        int no_of_odds=0;
        for(int i=0;i<26;i++){
            if(hash_array[i]%2!=0){
                no_of_odds++;
                if(no_of_odds>k) return false;
            }
        }
        return true;
     }
 };