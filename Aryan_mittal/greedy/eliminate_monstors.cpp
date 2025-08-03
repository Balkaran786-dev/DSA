// eliminate that monstor first that is taking the least time to reach the city..


class Solution {
    public:
        int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
            int n=dist.size();
            vector<double> time(n);
            for(int i=0;i<n;i++){
                time[i]=(double)dist[i]/speed[i];
            }
            sort(time.begin(),time.end());
            int kill=1;
            int regain=1;
    
            for(int i=1;i<n;i++){
                  if((double)regain>=time[i]) return kill; // mtlab sword regain huyi hi nhi tab tak monstor aa hi gya.
                  kill++;
                  regain++;
            }
            return kill;
        }
    };