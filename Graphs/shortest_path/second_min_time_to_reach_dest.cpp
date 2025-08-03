//Here dijkstra is always used to find the shortest distance,
//but we have used to find the second shortest,
//every node has two distances, dist1 and dist2,
//dist1 is the minimum distance to reach that node,
//dist2 is the second minimum distance to reach that node,
//if the new distance is less than dist1, then dist2 = dist1 and dist1 = new distance,
//if the new distance is greater than dist1 but less than dist2, then dist2 = new distance,

//why we only need to visit the every node twice only,??
//it is beacuse here all edges are similar agr ek edge  ko do baar krenge visit toh hume min and second min mil hi jayega,
// third baar humesha usse jada hi milega..
//isiliye when the second dist2 of last node is found , return it.

//dry run it for the example 1 , get more clarity..

//also, jo red green vala scene hai, that is very easy , just plot a number line and see how didvidion helps you track in which section you r
// and do u even need to wait, till what time and if no, then move withoutt a second thought.


class Solution {
public:
    using pp = pair<int, int>;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 1});
        dist1[1]=0;
        while (!pq.empty()) {
            pp curr = pq.top();
            pq.pop();
            int timePassed=curr.first,node=curr.second;

            if (dist2[n] != INT_MAX) {
                return dist2[n];
            }

            int div = timePassed / change;
            if (div % 2 == 1) { // Odd =>>>> Red....
                timePassed = change * (div + 1);
            }

            for (auto& neigh : graph[node]) {
                if (dist1[neigh] > timePassed + time) {
                    dist2[neigh] = dist1[neigh];
                    dist1[neigh] = timePassed + time;
                    pq.push({timePassed + time, neigh});
                } else if (dist2[neigh] > timePassed + time &&
                           dist1[neigh] != timePassed + time) {  //it needs to be strictly larger
                    dist2[neigh] = timePassed + time;
                    pq.push({timePassed + time, neigh});
                }
            }
        }

        return -1;
    }
};


//2nd solution using BFS, beacuse the edge weight is same
class Solution {
public:
    using pp = pair<int, int>;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        queue<pp> qu;
        qu.push({0, 1});
        dist1[1]=0;
        while (!qu.empty()) {
            pp curr = qu.front();
            qu.pop();
            int timePassed=curr.first,node=curr.second;

            if (dist2[n] != INT_MAX) {
                return dist2[n];
            }

            int div = timePassed / change;
            if (div % 2 == 1) { // Odd =>>>> Red....
                timePassed = change * (div + 1);
            }

            for (auto& neigh : graph[node]) {
                if (dist1[neigh]==INT_MAX) {    //jo first time visit kr rhe ho,vohi min weight hoga
                    dist1[neigh] = timePassed + time;
                    qu.push({timePassed + time, neigh});
                } else if (dist2[neigh]==INT_MAX &&
                           dist1[neigh] != timePassed + time) {  // jo second time visit kr rjhe ho,and also it needs to be strictly larger than the first time vala distnace
                    dist2[neigh] = timePassed + time;
                    qu.push({timePassed + time, neigh});
                }
            }
        }

        return -1;
    }
};