// this approach failed for 4 testcases using maxheap + greedy
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // o(n^2) one by one from starting, check if we can reach there
        // each time for every building , push the req help in a priority queue, then for top elements use all your ladders and then start using bricks , so this till you get a building where you can't reach.

        // use binary search instead of linaer search..in bool function use the same approach as you used above.

        // greedy + prority queue;
        
        int n=heights.size();
        priority_queue<int> pq;
        int i=0;
        int reached=0;
        while(i < n-1){
            if(heights[i]<heights[i+1]){
                int help=heights[i+1]-heights[i];
                if(help>bricks) break;
                else{
                    pq.push(help);
                    bricks-=help;
                }
            }
            i++;
            reached++;
        }

        while(i<n-1){
            int help=heights[i+1]-heights[i];
            if(help>0){
                if(ladders!=0){
                    if(pq.empty() || help>=pq.top()){
                        ladders--;
                        reached++;
                    }
                    else{
                        ladders--;
                        bricks+=(pq.top()-help);
                        pq.pop();
                        pq.push(help);
                        reached++;
                    }
                }
                else{
                    if(bricks-help>=0){
                        reached++;
                        pq.push(help);
                        bricks-=help;
                    }
                    else break;
                }
            }
            else reached++;

            i++;
        }

        return reached;
    }
};




// using minheap..
// isme hum ladders use krte rhenge..
// jaise hi ladders khatam huye , we start using bricks for the smallest
// help for which we would have used a ladder...
// if we get exhausted with bricks, return i....

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
    