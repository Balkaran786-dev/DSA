class Solution {
public:
    vector<pair<int,int>> KMP(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();

        // Build LPS array
        vector<int> LPS(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = LPS[len - 1];
                else
                    LPS[i++] = 0;
            }
        }

        // Match pattern in text
        i = 0;
        int j = 0;
        vector<pair<int,int>> ans;
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
                if (j == m) {
                    ans.push_back({i-j,i});
                    j = LPS[j - 1];
                }
            } else {
                if (j != 0)
                    j = LPS[j - 1];
                else
                    i++;
            }
        }
        return ans;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        // 1. Flatten the grid into two strings:
        string h, v;
        int n = grid.size();
        int m = grid[0].size();
        // h: reading rows left to right.
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                h += grid[i][j];

        // v: reading columns top to bottom.
        for(int j=0; j<m; j++)
            for(int i=0; i<n; i++)
                v += grid[i][j];

        // 2. Find all intervals (start and end positions) where the pattern appears in h and v.
        vector<pair<int,int>> horiInterval = KMP(h, pattern);
        vector<pair<int,int>> verInterval = KMP(v, pattern);

        // 3. Mark these intervals using a difference array technique (+1 at start, -1 after end).
        vector<int> hh(h.length(), 0);
        for(int i=0; i<horiInterval.size(); i++){
            if(horiInterval[i].first < hh.size())
                hh[horiInterval[i].first]++;
            if(horiInterval[i].second< hh.size())
                hh[horiInterval[i].second]--;
        }
               
        vector<int> vv(v.length(), 0);
        for(int i=0; i<verInterval.size(); i++){
            if(verInterval[i].first < vv.size())
                vv[verInterval[i].first]++;
            if(verInterval[i].second < vv.size())
                vv[verInterval[i].second ]--;         
        }

        // 4. Build prefix sums to know which cells are inside a pattern match.
        for(int i=1 ;i<hh.size(); i++) {    // hh and vv are of same size
            hh[i] += hh[i - 1];
            vv[i] += vv[i - 1];
        }

        // 5. We can convert a 2D index to 1D index using the below formula
        // 1D_rc_index = r * No of columns + c
        // 1D_cr_index = c * No of rows + r
        // 6. Loop through the matrix and update ans using below condition
        // if(h[1D_rc_index] && v[1D_cr_index]) ans++;
        int ans = 0;
        for(int r=0; r<n; r++)
            for(int c=0; c<m; c++)
                if(hh[r * m + c] && vv[c * n + r])
                    ans++;
        return ans;
    }
};