//bruteforce
// two for loops
//   unordered_map<char,int> mp;
//  for(i=0 -> n)
//     mp['a']=1; mp['b']=1; mp['c']=1; cnt=0;
//        for(j=i -> n)
//           mp[s[j]]--;
//           if(mp[s[j]]==0) cnt++;
//           if(cnt==3){  //mtlab eske baad vali saari substrings are also fine to take
//                total_ans+=(n-i);
//                break;
//            } 



//a lill better designed by me only
int countSubstring(string s){
    // Write your code here.
    int lo=0,hi=0,n=s.size();
        int cnt=0;
        int ans=0;
        unordered_map<char,int> mp;
        mp['a']=1;
        mp['b']=1;
        mp['c']=1;
        while(hi<n){
            mp[s[hi]]--;
            while(mp[s[hi]]==0) cnt++;
                 if(cnt==3){
                 ans+=(n-hi);
                 mp[s[lo]]++;
                 if(mp[s[lo]]>0) cnt--;
                 lo++;
            }
            hi+=1;
        }
        return ans;
}

// mine-> complement approach:-

// total subarrays with at least one occurence of all three characters = total_subarrays - subarrays with at most any two characters...

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n=s.size();
            int l=0,r=0;
            unordered_map<char,int> mp;
            long long count=0;
            while(r<n){
                mp[s[r]]++;
                while(mp.size()==3){
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                }
                count+=(r-l+1);
                r++;
            }
            return (1LL*n*(n+1)/2) - count;
        }
    };

//striver optimal approach
