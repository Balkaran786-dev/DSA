class Solution {
public:
#define map_2d unordered_map<int, unordered_map<int, bool>>  
//map of map

    int grid_size = 1e6;

    bool bound_checker(int r, int c) {
        return (r >= 0 && r < grid_size && c >= 0 && c < grid_size);
    }
    bool search(vector<int>& source, vector<int>& target, map_2d& blocked,
                int num_blocks) {
        map_2d visited;
        visited[source[0]][source[1]] = true;

        queue<pair<int, int>> q;
        q.push({source[0], source[1]});

        int area = 1;
        int max_area = (num_blocks * (num_blocks - 1)) / 2;

        vector<int> rdir = {0, 0, 1, -1};
        vector<int> cdir = {1, -1, 0, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r == target[0] && c == target[1]) {
                return true;
            }

            if (area > max_area) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + rdir[i];
                int nc = c + cdir[i];

                if (bound_checker(nr, nc) and !visited[nr][nc] and
                    !blocked[nr][nc]) {
                    area += 1;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                          vector<int>& target) {
        /*
   O(n * n) = O(n^2) = O(10^6 * 10^6) = O(10^12) = 1 TB
   O(b(b - 1) / 2 * 2) = O(b(b - 1)) = O(b^2)
   */

        map_2d blocks;
        int num_blocks = 0;
        for (auto point : blocked) {
            num_blocks++;
            blocks[point[0]][point[1]] = true;
        }

        return search(source, target, blocks,num_blocks) and
               search(target, source, blocks,num_blocks);
    }
};