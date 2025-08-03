#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int f(int mask, int pos)
{
    if (mask == (1 << n) - 1) // if all the cities are visited.
    {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0) // check if the 'city' is unvisited by checking 'cityth' bit.
        {
            int newAns = dist[pos][city] + f(mask | (1 << city), city); // mark this city visited and look for aage ka path from this city.
            
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    cout << "Enter no. of cities: ";
    cin >> n;
    vector<vector<int>> cost(n);
    cout << "Enter cost of each city from every city: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;
            cost[i].push_back(ele);
        }
    }
    dist = cost;
    dp = vector<vector<int>>(1 << n, vector<int>(n, -1));
    cout << "Minimum cost: " << f(1, 0) << endl;
}