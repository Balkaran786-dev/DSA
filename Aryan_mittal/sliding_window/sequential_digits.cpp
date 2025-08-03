// 1. recursion
//Fix the starting digit then do a recursion that tries to append all valid digits.
// BRUTE FORCE-> start building your number eg low=100 and high=300
//start building 1->12->123(ans)->1234->backtrack->2->23->234(ans)->2345->backtrack->3->34->345(got no answer this time and we are out of range (base case) so return)

// 2. take a string of 123456789
// start from every digit and keep appending the string in an ans jaha tak range mein, jaise pehle , 1 12 123 1234 aage fer out of bound chli gayi 
// then 2 23 234...so on. 
// then change the starting point and do the same thing
// at last sort the vector and return it..


//3. optimise the better one..
// take window size from min_len to max_len....
// see the code....

class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            string s="123456789";
            int min_len=to_string(low).size();
            int max_len=to_string(high).size();
            
            vector<int> ans;
            
            while(min_len<=max_len){
                 int l=0,r=min_len-1;
                 int size=min_len;
                 while(r<9){
                    int val=stoi(s.substr(l,size));
                    if(val>=low && high>=val){
                        ans.push_back(val);
                    }
                    r++;
                    l++;
                 }
                 min_len++;
            }
    
            return ans;
        }
    };