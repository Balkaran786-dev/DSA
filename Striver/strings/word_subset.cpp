// hume ultimately yehi pta krna hai ki
// a word in word1 should have all the words in words2 in them as subset(eski definition alag hai),
// so jo har ek alphabet ki max freq hogi in all the words in words2, agr hum voh store krvale
// and uske sath compare kren the freq array of a word in word1, that will be much better rather than forming a separate freq vector 
// for evry word in word2, beacuse for ex,
// every word in word2 has 'p' single times in them and one word has it 4 times, so in freq array we store 4 for p
// and if a word in word1 has freq of p<4, we will say no to it there only.


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);  // Stores the max frequency of each character in words2
        
        // Compute the max frequency of each character across all words in words2
        for (const string& word : words2) {
            vector<int> tempFreq(26, 0);
            for (char ch : word) {
                tempFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], tempFreq[i]);
            }
        }
        
        vector<string> ans;
        
        // Check each word in words1
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
