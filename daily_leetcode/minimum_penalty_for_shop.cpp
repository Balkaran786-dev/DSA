class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int cnt_Y=0;
        int cnt_N=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') cnt_Y++;
        }
        
        int penalty=INT_MAX;
        int hour=-1;
        for(int i=0;i<=n;i++){
            if(penalty>cnt_Y+cnt_N){
                 hour=i;
                 penalty=cnt_Y+cnt_N;
            }

            if(i!=n){
                if(customers[i]=='Y'){
                    cnt_Y--;
                }
                else{
                    cnt_N++;
                }
            }
        }
        return hour;
    }
};