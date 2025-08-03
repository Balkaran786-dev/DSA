// solved using topological + relaxation of edges
// it will have a TC of o(V+E)

// why used this instead of any standard algo like dijkstra; beacuse
//  any stanadrd algo has more TC than this , it would be overkill to do this by any stanadrd algo

// Also why it got successful,
//  we are finding the distance to every node in a sequential way,
//  like for ex the topo order is 9,7,4,3,2,1
//  for 4, we know that we can reach it through 9 or 7, for which we would have already computed the distnace,
//  so , we can find the shortest distance to 4 also, beacuse 4 is only reachable from them acc to teh order.

// Shortest path from any src :
// 1.Perform toposort and store the order in a stack
// 2.Once the source node is given, pop the elements in the stack until the stack's top is the source
// 3. Rest is the same

class Solution
{
public:
    void dfs(stack<int> &st, vector<int> &visited, int start, vector<vector<pair<int, int>>> &adj)
    {
        visited[start] = 1;
        for (auto ele : adj[start])
        {
            if (visited[ele.first] == -1)
            {
                dfs(st, visited, ele.first, adj);
            }
        }
        st.push(start);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // code here..........
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // find topo order
        // o(V+E)
        vector<int> visited(V, -1);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == -1)
            {
                dfs(st, visited, i, adj);
            }
        }

        vector<int> dist(V, INT_MAX);

        dist[0] = 0;
        /// o(V+E).
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] == INT_MAX)
                continue; // Skip unreachable nodes

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
