class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to track smallest jumps
        
        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            // If next building is taller, handle the gap
            if (diff > 0) {
                pq.push(diff);
                
                // If we have used more jumps than ladders available, start using bricks
                if (pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                
                // If bricks are exhausted, we can't go further
                if (bricks < 0) return i;
            }
        }
        
        return n - 1; // If we reach the end
    }
};