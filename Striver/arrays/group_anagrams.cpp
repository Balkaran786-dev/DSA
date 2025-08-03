// categorize by sorting..
// based on the idea, that if two anagrams are sorted, they will be equal..
// time -> nklogk + m(used in vec)(maximum same ele after sorting are m), assuming k as the length of largest string...

class Solution {
public:  
    //categorize by sorting
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> vec;
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;  // key mein hum sorted part ko store krenge, and values mein jo jo ele sorting krke uske brabr honge, unko insert kreneg.
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto ele:mp){
            for(auto part:ele.second){
              vec.push_back(part);
            }
            ans.push_back(vec);
            vec.clear();
        }
        return ans;
    }
};

// categorize by frequency string..
// based on the idea that two anagrams has same frequency string.
// here we don't sort our string , but we form the frequency string of it and put them in hashmap.
// ex-> abaab  -> a3b2
// here every string of max length assumned as k, is traversed 26 times ,
// o(n*k) time 
// o(m) space of hashmap.
