vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int l1=0,h1=N-1;
        int l2=0,h2=N-1;
        int min_cost=0;
        int max_cost=0;
        // Write Your Code here
        
        while(l1<=h1 && l2<=h2){
            min_cost+=candies[l1++];
            max_cost+=candies[h2--];
            h1-=K;
            l2+=K;
        }

        return {min_cost,max_cost};
    }