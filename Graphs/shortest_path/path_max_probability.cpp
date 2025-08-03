//kyunki hume sirf ek endNode tak ki hi probability cahhiye, isiliye jaise hi voh pq
//se bhafr nikli thats the max probabity, kyunki vaise bhi usse acha ans toh abb nhi miliga, isiliye toh hum
//normal dijkstra mein node ko pq se nikalr visited kr dete the, isisliye as soon as we take out the endNode from
//pq, we return the probability of that node.

//o((v+E)logV)

class Solution {
public:
    using pp=pair<double,int>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double> pro(n,0.0);
        unordered_set<int> visited;
        priority_queue<pp> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            pp curr=pq.top();
            pq.pop();
            double pr=curr.first;
            int node=curr.second;
            if(node==end_node){
                return pr;
            }
            visited.insert(node);
            for(auto neigh:graph[node]){
                int ele=neigh.first;
                double p=neigh.second;
                if(!visited.count(ele) && pr*p>pro[ele]){
                    pro[ele]=pr*p;
                    pq.push({pro[ele],ele});
                }
            }
        }
        return pro[end_node];
    }
};