// if we need to print them in ascending order, then 
// time->o(sqrt(n));
// space->o(sqrt(n));

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> vec;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                cout<<i<<" ";
                if(n/i!=i){
                    vec.push_back(n/i);
                }
            }
        }

        int sz=vec.size();
        for(int i=sz-1;i>=0;i--){
            cout<<vec[i]<<" ";
        }
    }
};