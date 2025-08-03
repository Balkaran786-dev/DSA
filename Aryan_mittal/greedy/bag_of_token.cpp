// we can use every token at most once.....
// sort krnege..
// intitution:- if our power is less than the lowest possible token available,
// we will try to face down with the largest possible card available but for that 
// score must be at least 1, 
// if both condtion are not true, that is neither our power is >= lowest possible card nor our score is at least 1, 
// we will return the max score possible yet.

// sort isiliye kiya...
class Solution {
    public:
        int bagOfTokensScore(vector<int>& tokens, int power) {
            sort(tokens.begin(),tokens.end());
            int n=tokens.size();
            int l=0;
            int r=n-1;
            int max_score=0;
            int curr_score=0;
            while(l<=r){
                if(power>=tokens[l]){ // score increase krne ke liye, we will try the lowest possible card.
                    curr_score++;
                    power-=tokens[l++];
                }
                else if(curr_score>=1){ // power increase krne ke liye, we will try the largest possible card.

                    power+=tokens[r--];
                    curr_score--;
                }
                else{
                    break;
                }
                max_score=max(max_score,curr_score);
            }
    
            return max_score;
        }
    };