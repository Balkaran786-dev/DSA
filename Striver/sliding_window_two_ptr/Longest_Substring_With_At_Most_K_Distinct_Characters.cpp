//most optimised
#include<bits/stdc++.h>
int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int n=s.size();
   unordered_map<char,int> mp;
   int l=0,r=0,max_len=0;
   while(r<n){
      mp[s[r]]++;
      if(mp.size()>k){
         mp[s[l]]--;
         if(mp[s[l]]==0) mp.erase(s[l]);
         l++;
      }
      if(mp.size()<=k) max_len=max(max_len,r-l+1);
      r++;
   }
   return max_len;
}
