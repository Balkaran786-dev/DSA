class Solution {
public:
    static bool cmp(vector<int> &a1,vector<int> &a2){
        return a1[1]>a2[1];

        /*  OR
        
        double d1=static_cast<double> (a1[0]*a1[1])/a1[0];  // total_units/total_boxes = unit_per_box that is already given,so we can directly sort acc to it..
        double d2=static_cast<double> (a2[0]*a2[1])/a2[0];  

        return d1>d2;
        */
       
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        int n=boxTypes.size();
        for(int i=0;i<n;i++){
            if(truckSize==0) break;
            int boxes=boxTypes[i][0];
            int units=boxTypes[i][1];
            if(boxTypes[i][0]<=truckSize){
                ans+=boxes*units;
                truckSize-=boxes;
            }
            else{
                ans+=truckSize*units;  //jitna trucksize rehta hai abb utne hi boxes chahiye..
                truckSize=0;
            }
        }
        return ans;
    }
};