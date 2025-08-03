//need to use the fact that all words are of same size...
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words[0].size();
        int n = words.size();
        int tl = m*n;
        unordered_map<string,int>mp1;
        vector<int>ans;
        for(auto word : words) {
            mp1[word]++;
        }
        if(tl >s.size()) {
            return ans;
        }

        for(int i = 0; i<m; i++) {  //inhi possible index se hum start kr skte hain,baki ke hum intermediate consider kr hi lete hain, nikalte waqt.

            unordered_map<string,int>mp2;  //temp map to store the currently foound substrings
            int left = i;  //yeh left hum increase tabhi krenge, jab ya toh concatendated substring mil jaye , ya phir
            // wrong substring mile, isie move m se hi krnege...
            for(int j = i; j<=s.size()-m; j+=m) {
                string temp = s.substr(j,m);

                if(mp1.find(temp) != mp1.end()) {
                    mp2[temp]++;

                    while(mp2[temp]>mp1[temp]) { //extra mil gya, that  is not needed...
                        mp2[s.substr(left,m)]--;
                        left+=m;
                    }
                    if(j-left+m == tl) {
                        ans.push_back(left);
                        mp2[s.substr(left,m)]--;  //hum sirf pehle vali substring ko hateyenge
                        //  kyunki may be bacchi hui substrings ke sath fer concatenated string ban jaye...
                        left+=m;
                    }
                }
                else{
                    mp2.clear();
                    left = j+m;

                }
            }
        }
        return ans;
        
    }
};