class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // elimination method,
        int n=gas.size();
        int totalGas=0;
        int totalCost=0;
        for(int i=0;i<n;i++){
            totalCost+=cost[i];
            totalGas+=gas[i];
        }

        if(totalCost>totalGas) return -1; //agr jitni totalcost hai, vahi humari, totalgas se kam hai, toh koi possible solution hoga hi nhi
        int currGas=0;
        int start=0;
        for(int i=0;i<n;i++){   //varna, hum har ek index pe check krte rhenge
        // kitna currGas hai, agr yeh negative hua, means jo start point hum , assume, kar rhe the voh nhi hai,
        // infact, if we had assumed start=i, and now at j you realised that it can't be start, so any index from ito j, won't be even a start, because un saaro pe currGas kisi na kisi tarah negative aa hi jati , so hum currGas ko 0 rkhenge and start ko next index magenge, pechle vale saare toh eliminate ho gaye....
           currGas+=gas[i]-cost[i];
           if(currGas<0){
            currGas=0;
            start=i+1;
           }
        }
        return start;
    }
};