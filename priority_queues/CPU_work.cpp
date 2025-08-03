class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            /*
            1st observation, to perform tasks in minimum intervals, we need to perform
            those tasks first having higher frequency.. apply this on ABA n=2.
            
            2nd observation, we just need to find the minimum intervals, not the order of execution, so we are focusing on just frequencies of tasks , not on what task we r performing...
            we can store the frequencies of tasks in a priority queue,
            we know in n+1 intervals, one type of task can be performed only single time,
            To ensure this, once we perform a task, till n+1 time, we put this in a temporary vector,
            after this n+1 intervals, we again put these frequencies in the prority queue and start performing it
            when both our priority queue and temp vector is empty , return the totaltime(this is incremented in every interval whther any task is done or not(idle)) 
            
            what if the type of tasks are more than n+1 , 
            isiliye hume for loop ke andr 
            dono ko means priority queue and vector ko check kiya ki dono empty ho
            */
            int sz=tasks.size();
    // calculating freq
            unordered_map<char,int> mp;
            for(int i=0;i<sz;i++){
                mp[tasks[i]]++;
            }
    // pushing freq in priority queue
            priority_queue<int> pq;
            for(auto ele:mp){
                pq.push(ele.second);
            }
    
            int total_time=0;
            while(!pq.empty()){
                //temporary vector
                vector<int> temp;
    
                //n+1 time intervals we are going to perform only unique tasks
                for(int i=0;i<=n;i++){
                    
                    if(!pq.empty()){
                        int freq=pq.top();
                        pq.pop();
                        if(freq-1!=0){
                            temp.push_back(freq-1);
                        }
                    }
    
                    total_time++;        // even agr task nhi perform hua, ill put an idle,
                    if(pq.empty() && temp.empty()){
                        return total_time;
                    }
                }
    
                for(auto ele:temp){
                    pq.push(ele);
                }
            }
            return total_time;
        }
    };