class Solution {
public:
    void get_combinations(string digits,int idx,int n,string temp,vector<string> &ans,vector<string> buttons){
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        char ch=digits[idx];
        int p=ch-'0';

        for(int i=0;i<buttons[p].size();i++){
            
            get_combinations(digits,idx+1,n,temp+buttons[p][i],ans,buttons);
            
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> buttons={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        int idx=0;
        int n=digits.size();
        if(n==0) return ans;
        string temp;
        get_combinations(digits,idx,n,temp,ans,buttons);
        return ans;
    }
};