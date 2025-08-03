// o(N!) time o(N) space
// if we would have passed the str by value , time would have been o(N*N!);

class Solution {
    public:
        void get_all_combinations(string &tiles,unordered_set<string> &st,vector<bool> &used,string &str,int n){
                 st.insert(str);
                 for(int i=0;i<n;i++){
                    if(!used[i]){
                        str+=(tiles[i]);
                        used[i]=true;
                        get_all_combinations(tiles,st,used,str,n);
                        str.pop_back();
                        used[i]=false;
                    }
                 }
        }
        int numTilePossibilities(string tiles) {
            int n=tiles.size();
            unordered_set<string> st;
            vector<bool> used(n,false);
            string str="";
            get_all_combinations(tiles,st,used,str,n);
            return st.size()-1;
        }
    };



// based on take and not take approach and at the end, we calculate all possible permutations of that ..
// its important to do sorting beacuse 
// for example wwe have CDC , at last it will give CD and DC as unique combinations hence will 
// calculate their permutations separately, however DC will come in the permutation of CD , so no need to 
// calculate its permutation again,
// if we sort them as CCD, we would only get CD in our set.

// time o(N*2^N)  space o(N)

    class Solution {
        public:
            vector<int> fact;
            void fact_calculation(int n){
                fact[0]=1;
                for(int i=1;i<n+1;i++){
                    fact[i]=fact[i-1]*i;
                }
            }
            int get_permutations(string &temp){
                int sz=temp.size();
                vector<int> freq(26,0);
                for(auto ele:temp){
                    freq[ele-'A']++;
                }
        
                int num=fact[sz];
                int deno=1;
                for(int i=0;i<26;i++){
                    deno*=fact[freq[i]];
                }
                return num/deno;
            }
            void get_all_combinations(int idx,string &temp,unordered_set<string>&st,int n,string &tiles,int &count){
                if(idx==n){
                   if(!st.count(temp)){
                    st.insert(temp);
                    count+=get_permutations(temp);
                   }
                   return;
                }
        
                get_all_combinations(idx+1,temp,st,n,tiles,count);
                temp+=(tiles[idx]);
                get_all_combinations(idx+1,temp,st,n,tiles,count);
                temp.pop_back();
                return;
            }

            int numTilePossibilities(string tiles) {
                sort(tiles.begin(),tiles.end());
                int n=tiles.size();
                unordered_set<string> st;
                int idx=0,count=0;
                string temp="";
                fact.resize(n+1);
                fact_calculation(n);
                get_all_combinations(idx,temp,st,n,tiles,count);
                return count-1;
            }
        };