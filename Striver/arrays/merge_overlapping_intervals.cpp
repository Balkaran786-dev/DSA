// //o(nlogn + n^2) time   o(n) space
// /*
// vector<int> ans;
// for(int i=0;i<n;i++){
//    int start=vec[i][0];
//    int end=vec[i][1];

//    if(!ans.empty() && end<=ans.back()[1]) continue;  // to skip the merge intervals.. take example of (1,6) in ans and in array we have (2,4) or (2,6)  this will already be merged in (1,6)
     
//    for(int j=i+1;j<n;j++){
//        if(vec[j][0]<=end){
//            end=max(end,vec[j][1]);
//        }
//        else{
//           break;   // agar yeh vale ka start of interval hamare current vale ke start of the interval se jada hai, toh agle vale toh for sure jada hi honge , toh break krna is bettre.
//        }
//    }
//    ans.push_back({start,end});
// }*/




// // optimal solution.
// //o(nlogn+n)-time  o(n)-space
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         int n=intervals.size();
//         vector<vector<int>> ans;
//         vector<int> last={intervals[0][0],intervals[0][1]};  
//         for(int i=1;i<n;i++){
//             if(last[1]>=intervals[i][0] && last[1]<=intervals[i][1]){  //2nd condition is if its like (1,4),(2,3) then you just need to ignore the second one beacuse it is already inside it
//                 last[1]=intervals[i][1];
//             }
//             else if(last[1]<intervals[i][0]){   //not overlapping
//                 ans.push_back(last);
//                 last=intervals[i];
//             }
//         }
//         ans.push_back(last);  //ek last bach gya usko bhi dalo
//         return ans;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

int getMaxConsecutiveHidden(vector<int>& commits) {
    int n = commits.size();
    int max_hidden = 0;
    int l = 0; // left pointer

    for (int r = 0; r < n; r++) {
        // Move left pointer until consecutive condition holds
        while (commits[r] - commits[l] != r - l) {
            l++;
        }
        // Valid block: commits[l..r] are consecutive integers
        if (r - l - 1 > 0) {
            max_hidden = max(max_hidden, r - l - 1);
        }
    }
    return max_hidden;
}

int main() {
    vector<int> commits = {1, 3, 4, 5, 6, 9};
    cout << getMaxConsecutiveHidden(commits) << "\n"; // Output: 2
}
