// my own approach
// move from back
// if any space comes,continue,
// otherwise there is definitely a character.
// so to collect that word, we run the inner loop.
// then, with help of substr, ans jab khali hoga tabh hum space add nhi krenge ,sidha
// word add krnge otherwise, hum pehle space add krke fer word add krenege.

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
    
        string ans="";
        for(int i=n-1;i>=0;i--){
            
            if(s[i]==' ') continue;

            int end=i;
            while(i>=0  && s[i]!=' '){
                i--;
            }

            if(ans.size()>0){
                ans+=" ";
            }
            ans+=s.substr(i+1,end-i);
        }

        return ans;

        return ans.substr(1);
    }
};


// shradha approach
// reverse vali approach, 
// 1st reverse to get all words at their correct position
string reverseString(string &s){
	// Write your code here.
	int n=s.size();
        
        reverse(s.begin(),s.end());

        string ans="";
        for(int i=0;i<n;i++){

            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            
            reverse(word.begin(),word.end());
            if(word.size()>0){
				if(ans.size()>0){
                     ans+=" ";
				}
                ans+=word;
            }

        }

        return ans;	
}