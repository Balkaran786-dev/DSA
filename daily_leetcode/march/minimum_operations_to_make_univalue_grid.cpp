// to check that we can make all these numbers equal a number
// with the help of x, we need to see the remainder of all the numbers after dividing by x should be same...if it is not return -1
// for min operations,
// hume jo number hai voh max and min value ke andr ka hi rkhna hoga..
// also, it should be giving the same remainder after dividing by x.
// so, what we can do, sort the numbers and we take centre ki koi two values mein se koi ek in case of even numbers
// or centre ki value in case of of odd numbers and we make every number equal to it.
// to calculate operations, we can subtract the number from the chosen number and divide the diff by x, it would definitely be comning as an integer..


class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m=grid.size();
            int n=grid[0].size();
            vector<int> vec(m*n);
    
            int k=0;
            int remainder=grid[0][0]%x;
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                     if(remainder!=grid[i][j]%x) return -1;
                     vec[k++]=grid[i][j];
                }
            }
            
            sort(vec.begin(),vec.end());
            int median=vec[(m*n)/2];
            int operations=0;
            for(int i=0;i<k;i++){
                  operations+=(abs(vec[i]-median))/x;
            }
    
            return operations;
        }
    };




// 462 question very similar to this....

    class Solution {
        public:
            int minMoves2(vector<int>& nums) {
                int n=nums.size();
                sort(nums.begin(),nums.end());
                int median=nums[n/2];
                int moves=0;
                for(int i=0;i<n;i++){
                    moves+=abs(nums[i]-median);
                }
                return moves;
            }
        };