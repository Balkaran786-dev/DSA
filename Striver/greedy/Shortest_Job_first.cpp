// we r given with the execution time of each process,
// SIF, tells us to exceute the process in the increasing order of their exceution time,
// waiting time for the first process = 0;
// waiting time for the second process = exceution time of first process;
// waiting time for the third process = exceution time of first + second process;
// and so on...

// so we sort the array , since processes needs to be exceuted in the increasing order of their exceution time,
// we need to sum up the waiting time for all the processes and then divide it with n for finding the average..


long long solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        if(n==1) return 0;
        sort(bt.begin(),bt.end());
        long long sum=bt[0];
        long long prefix=bt[0];
        for(int i=1;i<=n-2;i++){
            prefix+=bt[i];
            sum+=prefix;
        }
        return sum/n;
}