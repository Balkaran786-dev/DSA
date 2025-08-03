//2434.
class Solution {
public:
  //I'm putting an ele in the ans only if there doesn't exit a smaller ele to its right in the s.
    string robotWithString(string s) {
        //maintain a vector that tells min right element to every index
        // put the current ele in t , put it in ans only, if there is no such min ele exist to its right rather than itself, after putting it in ans, check for the back ele of t ,pop it and put in ans till the ele in back of t doesn't has smaller ele in its right
        int n=s.size();
        vector<char> min_right(n,s[n-1]);
        for(int i=n-2;i>=0;i--){
            min_right[i]=min(min_right[i+1],s[i]);
        }

        string t="";
        string ans="";
        int i=0;
        while(i<n){
            t.push_back(s[i]);
            char min_ele=(i+1<n ? min_right[i+1]:s[i]);
            while(!t.empty() && t.back()<=min_ele){
                 ans.push_back(t.back());
                 t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            ans.push_back(t.back());
                 t.pop_back();
        }
        return ans;
    }
};