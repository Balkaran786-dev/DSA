class Solution {
    public:
        double averageWaitingTime(vector<vector<int>>& customers) {
            long sum=0;
            int n=customers.size();
            sum+=customers[0][1];  // first customer toh itna hi wait krega..
            long get_free=customers[0][0]+customers[0][1];
            for(int i=1;i<n;i++){
                int arrival=customers[i][0];
                int time=customers[i][1];
                if(get_free>=arrival){
                    sum+=get_free-customers[i][0];
                    sum+=time;
                    get_free+=time;
                }
                else{
                    get_free=arrival+time;
                    sum+=time;
                }
            }
            return (double)sum/n;
        }
    };