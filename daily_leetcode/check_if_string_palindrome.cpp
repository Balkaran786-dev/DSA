
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1) return false;
        
        stack<int> openBrackets;
        stack<int> unlocked;

        for(int i=0;i<n;i++){
           if(locked[i]=='0'){
                unlocked.push(i);
           }
           else if(s[i]=='('){
                openBrackets.push(i);
           }
           else{
               if(!openBrackets.empty()){
                openBrackets.pop();
               }
               else if(!unlocked.empty()){
                unlocked.pop();
               }
               else{
                return false;
               }
           }
        }

        while(!unlocked.empty() && !openBrackets.empty() && openBrackets.top()<unlocked.top()){
            openBrackets.pop();
            unlocked.pop();
        }

        if(!openBrackets.empty()){
            return false;
        }

        return true;
    }
};

