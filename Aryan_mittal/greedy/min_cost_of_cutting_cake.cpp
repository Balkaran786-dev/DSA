class Solution {
    public:
        int minimumCost(int m, int n, vector<int>& horizontalCut,
                        vector<int>& verticalCut) {
            sort(horizontalCut.begin(), horizontalCut.end(),greater<int>());
            sort(verticalCut.begin(), verticalCut.end(),greater<int>());
    
            int hori_p = 1, vert_p = 1;
            int cost = 0;
            int i = 0, j = 0;
            int size1 = m - 1;
            int size2 = n - 1;
            while (i < size1 && j < size2) {
                if (horizontalCut[i] >= verticalCut[j]) {
                    cost += (horizontalCut[i++] * hori_p);
                    vert_p++;
                } else {
                    cost += (verticalCut[j++] * vert_p);
                    hori_p++;
                }
            }
            while (i < size1) {
                cost += (horizontalCut[i++] * hori_p);
            }
            while (j < size2) {
                cost += (verticalCut[j++] * vert_p);
            }
    
            return cost;
        }
    };