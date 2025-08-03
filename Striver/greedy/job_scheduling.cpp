/*we want ki hum har ek job ko uski deadline ke njdiik hi kren,
so that if we do them far before their deadlines, they will block the other job too..
we are considering this, because hume max se maximum job krni hai.

also , consider we have two jobs with same dealine but with diff profits,
obviously hum jada profit vali ko jagah dene ki priority rkhenge,
may be only one spot is presnt, we will place the job with higher priority there.

so, we need to sort the jobs in dec order of profit.

procedure:-
we sort  jobs acc to their profit in dec order
then, we pick a job , and we will try from the dealine(this deadline vector will be of the size jo ki maximum dealine of any job ke brabr hoga.) of this job to agge ko, whether any of  spot is empty,
if yes, place it there.... in this way we do it..
 */





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


