// //1st approach  //o(N!+N*N!); time   
// // 1st string ke sabhi permuatation ko ek vector of string mein store krvalo
// // then turn by turn, sabhi ko string 2 mein through find function labh lo. at any step,
// // you r able to find any permutation in string 2 return true;





// //sliding window approach and 2 pointer approach, here once your size of window gets eual to length f string s1,
// // aap constant hi rkhoge , means l++ kiya matlab ek unit decrease hua, then r++ kiya matlab 1 unit increase kiya.
// // o(n) time , o(n) space
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int sz=s1.length();
//         int n=s2.length();
        
//         if(sz>n) return false;
//         vector<int> freq(26,0);
//         for(int i=0;i<sz;i++){
//             freq[s1[i]-'a']++;
//         }

//         int l=0,r=0;
//         vector<int> temp(26,0);
//         while(r<n){
//             temp[s2[r]-'a']++;

//             if(r-l+1==sz){
//                 if(temp==freq) return true;

//                 temp[s2[l]-'a']--;
//                 l++;
//             }

//             r++;  // in every case whether the size is equal or less than
//         }

//         return false;
//     }
// };


// #include <bits/stdc++.h>
// using namespace std;

// vector<string> getRequestStatus(const vector<string>& reqs) {
//     unordered_map<string, pair<deque<int>, deque<int>>> mp; // domain -> {5s, 30s}
//     vector<string> res;

//     for (int i = 0; i < reqs.size(); i++) {
//         auto &[w5, w30] = mp[reqs[i]];
//         int t = i;

//         while (!w5.empty()  && t - w5.front()  >= 5)  w5.pop_front();
//         while (!w30.empty() && t - w30.front() >= 30) w30.pop_front();

//         if (w5.size() >= 2 || w30.size() >= 5) res.push_back("[status: 429, message: Too many requests]");
//         else { w5.push_back(t); w30.push_back(t); res.push_back("[status: 200, message: OK]"); }
//     }
//     return res;
// }

// int main() {
//     vector<string> r1 = { "www.xyz.com", "www.abc.com", "www.xyz.com",
//     "www.pqr.com", "www.abc.com", "www.xyz.com",
//     "www.xyz.com", "www.abc.com", "www.xyz.com"};
//     for (auto &s : getRequestStatus(r1)) cout << s << "\n";
//     cout << "\n";
    
// }



#include <bits/stdc++.h>
using namespace std;

vector<string> getRequestStatus(const vector<string>& reqs) {
    unordered_map<string, pair<deque<int>, deque<int>>> mp; // domain -> {5s, 30s}
    vector<string> res;

    for (int i = 0; i < reqs.size(); i++) {
        string domain = reqs[i];
        auto &dqPair = mp[domain];
        deque<int> &w5  = dqPair.first;
        deque<int> &w30 = dqPair.second;

        int t = i;

        while (!w5.empty()  && t - w5.front()  >= 5)  w5.pop_front();
        while (!w30.empty() && t - w30.front() >= 30) w30.pop_front();

        if (w5.size() >= 2 || w30.size() >= 5)
            res.push_back("[status: 429, message: Too many requests]");
        else {
            w5.push_back(t);
            w30.push_back(t);
            res.push_back("[status: 200, message: OK]");
        }
    }
    return res;
}

int main() {
    vector<string> r1 = {"www.abc.com",
"www.hbc.com",
"www.abc.com",
"www.pqr.com",
"www.abc.com",
"www.pqr.com",
"www.pqr.com"};
    for (auto &s : getRequestStatus(r1)) cout << s << "\n";
    cout << "\n";
   
}




