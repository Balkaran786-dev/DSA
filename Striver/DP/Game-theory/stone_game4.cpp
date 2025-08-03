class Solution {
public:
   
//This f(i, turn) function returns:

//true: The current player can force a win with i stones left.

//false: The current player will lose, no matter what they do.
//dp[i][turn]: memoization table storing whether the current player can win with i stones left.
// this function is not only about alex, its about both,  hence when its alice turn, if she can make bob lose with any single move she eill return true otherwise , whateve she do if bob is always wining, then return false.
//when its bob turn, if he can make alice lose with any single move he will return true otherwise , whateve he do if alice is always wining, then return false.

    bool f(int i, int turn, vector<vector<int>> &dp) {
    if (i == 0) return false; // No moves left no matter who its is → current player will lose nayway

    if (dp[i][turn] != -1) return dp[i][turn];

    if (turn == 1) { // Alice's turn
        for (int k = 1; k * k <= i; ++k) {
            if (!f(i - k*k, 0,dp)) // If Bob loses in next state, yeh move aisa hai jisse bob haar skta hai
                return dp[i][turn] = true;
        }
        return dp[i][turn] = false;
    } else { // Bob's turn
        for (int k = 1; k * k <= i; ++k) {
            if (!f(i - k*k, 1 ,dp)) // If Alice loses in next state, yeh move aisa hai ki bob jit skta hai.
                return dp[i][turn] = true;
        }
        return dp[i][turn] = false;
    }
}

    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        int turn = 1;  //alice
        return f(n,turn,dp);
    }
};