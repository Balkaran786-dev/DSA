//memoization see in copy.. //o(N*4)*3 Time o(n*4)+(n) space



// tabulation  //o(N*4)*3 Time o(n*4)space
int ninjaTraining(int n, vector<vector<int>> &points){
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (4));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<=n-1;day++){
        for(int last=0;last<=3;last++){  //yeh bta rhe hain pechle din usne konsa task perform kiye...

            dp[day][last]=0;
            int maxi=-1;
            for(int task=0;task<=2;task++){ //abb voh konsa task perform kr skta hain.
                if(last!=task){
                   maxi=max(maxi,points[day][task]+dp[day-1][task]);
                }
            }
            dp[day][last]=maxi;
        }
    }
    return dp[n-1][3];
}


//o(N*4)*3 Time    o(4)space - constant
// space optimisation, since for every day, you just need the prev day data, so hum ek single
// array se bhi kaam chla skte hain,


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(4);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<=n-1;day++){
        vector<int> temp(4);
        for(int last=0;last<=3;last++){

            temp[last]=0;
            int maxi=-1;
            for(int task=0;task<=2;task++){
                if(last!=task){
                   maxi=max(maxi,points[day][task]+prev[task]);
                }
            }
            temp[last]=maxi;
        }

        prev=temp;
    }
    return prev[3];
}



