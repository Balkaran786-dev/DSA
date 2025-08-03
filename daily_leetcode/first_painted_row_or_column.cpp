//2661.
// simply, to reduce the time complexity of going to the matrix to find the position for every ele
// in arr, just pre-process their positions in a hashmap,
// them , make a freq row array of m size and freq col of n size,
// for every ele in arr, increment the freq of corrresponding row and col with the help of hashmap,
// just after every incremenet, check if the freq of that row == m , return i,
// check same for col,if the freq of that col == n,

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        unordered_map<int,pair<int,int>> mp; //pair of row and col
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]=make_pair(i,j);
            }
        }

        vector<int> freq_row(m,0);
        vector<int> freq_col(n,0);

        for(int i=0;i<m*n;i++){
            pair<int,int> pp=mp[arr[i]];
            int row=pp.first;
            int col=pp.second;
            freq_row[row]++;
            if(freq_row[row]==n) return i;
            freq_col[col]++;
            if(freq_col[col]==m) return i;
        }
        return -1;
    }
};