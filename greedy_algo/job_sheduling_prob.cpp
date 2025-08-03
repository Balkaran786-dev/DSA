//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
  public:
    bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
      int n=id.size();
      vector<Job> schedule(n);
      for(int i=0;i<n;i++){
         Job j;
         j.id=id[i];
         j.dead=deadline[i];
         j.profit=profit[i];
         schedule.push_back(j);
      }
      
      sort(schedule.begin(),schedule.end(), comparison);
      
      int maxi = schedule[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, schedule[i].dead);
      }

      vector<int> slot(maxi + 1,-1);

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = schedule[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += schedule[i].profit;
               break;
            }
         }
      }

      return {countJobs, jobProfit};
        
    }
};


