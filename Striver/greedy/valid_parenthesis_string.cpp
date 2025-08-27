////1.The most brute force one
// //trying out all possible combinations
// class Solution {
// public:
//     bool helper(string &s,int idx,int cnt){
//         if(cnt<0) return false;   //if traverse krte vakt kahi bhi yeh hua,that means a closing bracket didn't has its corresponding opening bracket,so return false there
//         if(idx==s.size()){        //after reaching end of each combination,if cnt =0 return true

//             if(cnt==0) return true;
//             else return false;
//         }

//         if(s[idx]=='('){         
//             return helper(s,idx+1,cnt+1);
//         }
//         else if(s[idx]==')'){
//             return helper(s,idx+1,cnt-1);
//         }
//         else{
//             bool res=helper(s,idx+1,cnt+1) || helper(s,idx+1,cnt) || helper(s,idx+1,cnt-1);
//             return res;
//         }
//     }
//     bool checkValidString(string s) { //o(3^N)-time o(N) -space
//          return helper(s,0,0);
//     }
// };


//3.The most optimised solution  o(n)-time and o(1)space
//we r maintaining a range just like we maintained a count when there was not aesteric,
//why range? because when an aesteric comes,we have 3 choices,so we can store the min and max
//value of cnt....

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int min=0;
//         int max=0;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 min++;
//                 max++;
//             }
//             else if(s[i]==')'){
//                 min--;
//                 max--;
//             }
//             else{
//                 min--;
//                 max++;
//             }
//             if(min<0) min=0;
//             if(max<0) return false;
//         }
//         return min==0;
//     }
// };





//2. the dp solution that optimised the first one in o(n^2) both space and time

