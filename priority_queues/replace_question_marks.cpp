/*
The cost does not depend on the order of characters. If a character c appears
 x times, the cost is exactly 0 + 1 + 2 + … + (x − 1) = x * (x − 1) / 2.
 
 due to this fact, humne last mein str ko sort kiya, fer ussi order mein ele ko dala..
 
*/
#define pp pair<int,char>
class Solution {
public:
    string minimizeStringValue(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                freq[s[i]-'a']++;
            }
            else{
              cnt++;
            }
        }
        priority_queue<pp,vector<pp>,greater<pp>> pq;  //hume sbse pehle voh ele chahiye apni string mein jo sbase least time a rha ho, agr 1 se jada ele ki freq same hui, toh dono mein se jo shota hua, voh prioritize krenge lene ke liye.

        for(int i=0;i<26;i++){
            pq.push({freq[i],'a'+i});
        }
        string str="";
        // I won't put ele in this manner..
        // i will actually put these element in a string and then sort it and then put ele in that order to make the smallest lexigraphically....

        while(cnt--){
            pp temp=pq.top();
            pq.pop();
            str.push_back(temp.second);
            pq.push({temp.first+1,temp.second}); 
        }
        sort(str.begin(),str.end());

        int p=0;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                s[i]=str[p++];
            }
        }
        return s;
    }
};