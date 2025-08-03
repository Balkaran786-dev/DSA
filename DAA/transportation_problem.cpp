#include <bits/stdc++.h> 
using namespace std; 

void northwestCorner(vector<vector<int>> cost, vector<int> supply, vector<int> 
demand) { 

    int m = supply.size(); 
    int n = demand.size(); 
    vector<vector<int>> alloc(m, vector<int>(n, 0)); 
    int i = 0, j = 0; 
    while (i < m && j < n) { 
        int x = min(supply[i], demand[j]); 
        alloc[i][j] = x; 
        supply[i] -= x; 
        demand[j] -= x; 

        if (supply[i] == 0) i++; 
        else if (demand[j] == 0) j++; 
    } 
    
    cout << "Allocation Matrix:\n"; 
    int totalCost = 0; 
    for (int r = 0; r < m; r++) { 
        for (int c = 0; c < n; c++) { 
 
 
 
            cout << alloc[r][c] << "\t"; 
            totalCost += alloc[r][c] * cost[r][c]; 
        } 
        cout << "\n"; 
    } 
    cout << "Total Transportation Cost = " << totalCost << endl; 
} 
 
int main() { 
    vector<vector<int>> cost = { 
        {2, 3, 1}, 
        {5, 4, 8}, 
        {5, 6, 8} 
    }; 
    vector<int> supply = {180, 80, 100}; 
    vector<int> demand = {100, 120, 140}; 
 
    northwestCorner(cost, supply, demand); 
    return 0; 
}