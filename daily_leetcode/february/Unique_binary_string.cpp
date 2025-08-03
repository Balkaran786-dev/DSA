// to find the complexity:-
// we need to know peigen hole principle:-
// basically if you have n given strings and in actual you can make
// 2^n strings, then you don't need to form all those 2^n strings and check all of them, whether
// they are present in the those n strings or not.
// In, worst case, you need to check only n+1 strings beacuse may be those first n strings
// are equal to those n strings..
// o(n) time
// o(n^2) space 


class Solution {
    public:
        bool get_string(int idx,int n,string &temp,string &ans,unordered_set<string> &st){
            if(idx==n){
                if(!st.count(temp)){
                    ans=temp;
                    return true;
                }
                return false;
            }
    
            temp.push_back('0');
            if(get_string(idx+1,n,temp,ans,st)) return true;
            temp.pop_back();
            temp.push_back('1');
            if(get_string(idx+1,n,temp,ans,st)) return true;
            temp.pop_back();
            return false;
        }
        string findDifferentBinaryString(vector<string>& nums) {
            int n=nums.size();
            string temp="";
            int idx=0;
            unordered_set<string> st;
            for(auto ele:nums){
                st.insert(ele);
            }
            
            string ans="";
            get_string(idx,n,temp,ans,st);
            return ans;
        }
    };


// You can optimise by converting the binary strings into equivalent decimal number
// and then checking first (n+1) numbers.

//o(n^2) time  n in converting the string to integer
// o(n) space
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n=nums.size();
            unordered_set<int> st;
            for(int i=0;i<n;i++){
                st.insert(stoi(nums[i],0,2));  // string,index,base 
            }
    
            for(int i=0;i<=n;i++){
                if(st.find(i)==st.end()){
                    string str=(bitset<16>(i)).to_string();
                    return str.substr(16-n);
                }
            }
            return "";
        }
    };