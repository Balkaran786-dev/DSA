// It gives TLE
// o(n*n!) time complexity.
// o(n) space                                       
class Solution {
    public: 
        void larg_validSequence(int n,vector<int> &ans,vector<int> &temp,int sz){
            if (n == 0) {
                if (ans.empty() || temp > ans) {
                    ans = temp;
                }
                return;
            }
    
            for (int i = 0; i < sz; i++) {
                if (temp[i] == -1) {
                    if (n == 1) {  // Special case for 1 (it appears only once)
                        temp[i] = 1;
                        larg_validSequence(n - 1, ans, temp, sz);
                        temp[i] = -1;
                    } else if (i + n < sz && temp[i + n] == -1) {  
                        temp[i] = temp[i + n] = n;
                        larg_validSequence(n - 1, ans, temp, sz);
                        temp[i] = temp[i + n] = -1;
                    }
                }
            }
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> ans;
            int sz=n*2-1;
            vector<int> temp(sz,-1);
            larg_validSequence(n,ans,temp,sz);
            return ans;
        }
    };


// 2ND SOLUTION doesn't give TLE

// 