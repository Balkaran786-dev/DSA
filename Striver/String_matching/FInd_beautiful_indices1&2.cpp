//1st method,
//naive approach, for evry starting point of s, make substring of size b and compare it with b,
// if yes, put it in a set,

//now, while doing it with a,
// whenever you find a index, check for all the elements in the set, whether anyone is at k distance if yes put that index in ans vector and break,
// now, evry time, you find an index, check again fro all elements in the set, hence/...
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
       
        int n=s.size();
        vector<int> ans;
        int n1=a.size();
        int n2=b.size();
        unordered_set<int> st;
        for(int i=0;i<=n-n2;i++){
            if(s.substr(i,n2)==b){
                st.insert(i);
            }
        }

        for(int i=0;i<=n-n1;i++){
            if(s.substr(i,n1)==a){
                for(auto ele:st){
                    if(abs(ele-i)<=k){
                        ans.push_back(i);
                         break;
                    }
                }
            }
        }

        return ans;
    }
};



//2nd method, using KMP + Two pointers
class Solution {
public:
    vector<int> KMP(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();
        vector<int> ans;
        // Form LPS array
        vector<int> LPS(m);
        LPS[0] = 0;
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[len] == pattern[i]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        // matching the pattern with the text
        i = 0;
        int j = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);
                j = LPS[j - 1];
            } else if (pattern[j] != text[i]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> vec1 = KMP(s, a);
        vector<int> vec2 = KMP(s, b);
        int n1 = vec1.size();
        int n2 = vec2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n1 && j < n2) { // Two pointers...
            if (abs(vec2[j] - vec1[i]) <= k) {
                ans.push_back(vec1[i++]);
            } else if (vec2[j] - vec1[i] >
                       k) { // means vec2 ka element bhut aage hai, we need to
                            // try next element in vec1
                i++;
            } else { // vec1[i]-vec2[j]>k means vec1 ka element bhut aage hai,
                     // we need to try next element in vec2
                j++;
            }
        }
        return ans;
    }
};