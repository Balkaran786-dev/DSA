/*

we can divide the intervals into 3 parts
:Left -> jab tak intervals ka end part would be lesser than the starting of the newInterval, they are not overlapping, 
so append them as it is.....

:Overlapping part -> jab tak intervals ka starting time newInterval k ending time se less or equal to hai, that is overlapping , so
to keep a track of it, hum start and end ka min and max respectively newInterval mein store krte rhenge......
jaise hi kisi interval ka start time > newInterval ke end time se, they are not overlapping with the newInterval anymore.

:right part -> uske baad ke saare ke saare interval non-overlapping hi honge.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        
        //left
        while(i<n && intervals[i][1]<newInterval[0]){
               ans.push_back(intervals[i]);
               i++;
        }
        //overlapping part
        while(i<n && intervals[i][0]<=newInterval[1]){
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                i++;
        }
        ans.push_back(newInterval);

        //right part
        while(i<n){
            ans.push_back(intervals[i]);
               i++;
        }
        return ans;
    }
};