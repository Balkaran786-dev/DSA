// rather than forming doing all split and cgecking sum,
// hum sarre no-of_1s ka sum le lete hai, that will tell total array mein kite 1 hai,
// then, iterate over array,
// hum kya sochenge, jis index pe honge, usko and uske pichle vale ele are in left part and all the  ahead ele are in right part.
// jaise hi koi zero ayega, we will add increment no_of_zeroes, this define the sum of left part and the no_of_ones defines sum of right part
// if 1 comes, we will decrement no_of_ones, because hum uss element ko left part mein consider krenge , so right part ka sum mein se ek 1 chala jayega.
// at every step, we will store it in score=max(score, no_of_1s+no_of_0s);

// edge case agr , manlo last element 0 hua and score uspe maximum hua, that means we are considering all element in left part
// and zero element in right which is wrong, so if we have 0 at the end, we will ignore it means we will conider it in right part.


class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int no_of_1s=0;
       
        for(int i=0;i<n;i++){
            
            no_of_1s+=(s[i]-'0');
        }
        
        int no_of_0s=0;
        int score=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]=='0' && i!=n-1){
               no_of_0s++;
            }
            else if(s[i]=='1'){
                no_of_1s--;
            }
            score=max(score,no_of_0s+no_of_1s);
        }
        return score;
    }
};