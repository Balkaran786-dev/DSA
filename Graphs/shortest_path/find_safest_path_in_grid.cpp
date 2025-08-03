class Solution {
public:
    using pp = pair<int, int>;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool is_possible(vector<vector<int>>& grid, int mid, int n) {
        if (grid[0][0] < mid)
            return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] && grid[ni][nj] >= mid) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pp> qu;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    qu.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        int maxi = INT_MIN;
        int steps = 1;
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz--) {
                pp curr = qu.front();
                qu.pop();
                int x = curr.first;
                int y = curr.second;
                for (int d = 0; d < 4; d++) {
                    int row = x + dir[d][0];
                    int col = y + dir[d][1];
                    if (row < 0 || col < 0 || row >= n || col >= n ||
                        grid[row][col] != 0)
                        continue;
                    grid[row][col] = steps;
                    maxi = max(maxi, steps);
                    qu.push({row, col});
                }
            }
            steps++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    grid[i][j] = 0;
                }
            }
        }
        int l = 0;
        int r = maxi;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (is_possible(grid, mid, n)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};