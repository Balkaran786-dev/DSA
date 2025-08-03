// brute force o(n*m) time   o(1) space


// better 
// used concept of factors and multiples.....

class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            int n=groups.size();
            int max_ele=INT_MIN;
            unordered_map<int,vector<int>> mp;  // ele,index
            for(int i=0;i<n;i++){
                max_ele=max(max_ele,groups[i]);
                mp[groups[i]].push_back(i);
            }
            
            unordered_set<int> values;
            vector<int> ans(n,-1);
            int sz=elements.size();
            for(int i=0;i<sz;i++){
               
                int val=elements[i];
                if(values.count(val)){
                    continue;
                }
                while(val<=max_ele){
                    if(mp.find(val)!=mp.end()){
                        for(int j=0;j<mp[val].size();j++){
                            ans[mp[val][j]]=i;
                        }
                        mp.erase(val);
                    }
                    val+=elements[i];
                }
                values.insert(elements[i]);
            }
            return ans;
        }
    };