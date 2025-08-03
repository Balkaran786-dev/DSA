//1st naive solution. o(n^2) time  and o(256) space.
// generating all possible substring



int solve(string str) {

  if(str.size()==0 || str.size()==1)
      return n;

  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so update your ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}



// sliding window technique  o(n) time and o(256) space
// technique:
// include a chacrter if it is not discovered yet and calculate the length and update if req
// include a charcter if it is discovered before but not presnet in the current substring and calculate the length and update if req
// doesn't include a character if it is discovered and presnt in the current substring..
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1) return n;
        int lo=0;
        int hi=0;
        unordered_map<char,int> mp; // character,index  //max to max 256 size ka ho jayega.

        int length=1;
        mp[s[0]]=0;
        hi+=1;
        while(hi<n){
             if(mp.find(s[hi])!=mp.end()){  //if the character is already discovered...
                int idx=mp[s[hi]];
                if(idx>=lo){   //means that character is present in the current substring
                  lo=idx+1;
                }  
                else{   //means that character is present in the map but it is not present in the current substring so, we can inckude it
                   length=max(length,hi-lo+1);  
                }
             }
             else{  //chacter is not yet discovered....
                length=max(length,hi-lo+1);
             }

             mp[s[hi]]=hi;
             hi+=1;
        }

        return length;

    }
};