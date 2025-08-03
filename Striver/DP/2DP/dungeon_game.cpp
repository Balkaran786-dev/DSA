//1st approach:- 
//Binary search on answers..
//matlab min=1 and max=1e9 health lekar, you will check ki kya aap iss heath se kisi bhi tarah bina mare pahunch skte hain





//memo..
class Solution {
public:
    int get_HP(int row,int col,int m,int n,vector<vector<int>>& dungeon,vector<vector<int>> &dp){
        if(row<0 || col<0 || row>=m || col>=n) return 1e9;

        if(row==m-1 && col==n-1){
            if(dungeon[row][col]>=0) return 1;  // means yeh return krega ki minimum health to 1 chahiye tanki voh survive kr jaye jab yahan aaye.
            return abs(dungeon[row][col])+1;  // abb jitne negative mein hai,utna positive mein chahiye +1 taki 0 na hoye yahan aakr
        }

        if(dp[row][col]!=-1) return dp[row][col];

        int right=get_HP(row,col+1,m,n,dungeon,dp);
        int down=get_HP(row+1,col,m,n,dungeon,dp);

        int health=min(right,down)-dungeon[row][col];  //yeh minus isiliye kiya, beacuse jab knight iss cell mein ayega, 
        //yah vala usme add hoga hi toh voh health hume pehle se lekar 
        //aane ki jarurat nhi, vaise bhi minimum chahiye, toh jo minimu 
        //heath chaiye princess tak reach krne mein - this cell value i
        //what we need to survive on this cell,  if this difference is 
        //positive means,kuch toh initial heath honi chaiye to survive 
        //this cell hence return as it is, is it zero or negative , 
        //matlab this cell contains a portion joke kafi power dega 
        //aapko that you can survive even if you have zero or lesser energy 
        //, so we return 1 as the minimum energy required to survive thi cell
        return dp[row][col]=( health<=0 ? 1 : health);

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return get_HP(0,0,m,n,dungeon,dp);
    }
};