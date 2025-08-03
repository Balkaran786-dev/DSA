class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        mp[5]=0;
        mp[10]=0;
        mp[20]=0;
        
        int sz=bills.size();
        for(int i=0;i<sz;i++){
            if(bills[i]==5){
                mp[5]++;
            }
            else if(bills[i]==10){
                mp[10]++;
                if(mp[5]!=0){  
                    mp[5]--;
                }
                else{         //if 5 dollar is not present return false
                    return false;
                }
            }
            else{
                mp[20]++;
                if (mp[10] > 0 && mp[5] > 0) {
                    // Case 1: Use one $10 and one $5
                    mp[10]--;
                    mp[5]--;
                } else if (mp[5] >= 3) {
                    // Case 2: Use three $5 bills
                    mp[5] -= 3;
                } else {
                    // Case 3: Not enough change
                    return false;
                }
            }
        }
        return true;
    }
};