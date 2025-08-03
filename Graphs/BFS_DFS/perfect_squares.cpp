class Solution {
public:
    bool is_perfect(int n) {
    int s = (int)sqrt(n);
    return s * s == n;
}
    int numSquares(int n) {
        cout<<is_perfect(17);
        vector<bool> visited(n + 1, false);
        int level = 1;
        queue<int> qu;
        qu.push(n);
        visited[n] = true;
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz--) {
                int ele = qu.front();
                qu.pop();
                for (int i = 0; i < ele; i++) {
                    int num = ele - i;
                    if (is_perfect(num)) {
                        int to_put = ele - num;
                        if(to_put==0) return level;
                        if (visited[to_put])
                            continue;
                        visited[to_put] = true;
                        qu.push(to_put);
                    }
                }
            }
            level++;
        }
        return 0;
    }
    
};