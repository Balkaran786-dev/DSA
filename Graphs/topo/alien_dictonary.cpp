// order is not possible in two cases:-
//1. cyclic dependencies:- abc, cde, asd;
//2. larger string ,with characters till the size of smaller string equal to smaller string , occurs before that smaller string



class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        // Step 1: Initialize graph with all unique characters
        for (const string &word : words) {
            for (char ch : word) {
                graph[ch]; // create empty list if not exists
                indegree[ch] = 0;
            }
        }

        // Step 2: Build edges between characters
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            int len = min(w1.size(), w2.size());

            bool found = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix comes after word (e.g., "abc", "ab") //evrything matches and some charcters are extra in first string, such that we have larger string before a smaller string, order not possible
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        // Step 3: Topological sort using BFS (Kahn's algorithm)
        queue<char> q;
        for (auto ele: indegree) {
            if (ele.second == 0) q.push(ele.first);
        }

        string order;
        while (!q.empty()) {
            char ch = q.front(); q.pop();
            order += ch;
            for (char neighbor : graph[ch]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() != graph.size()) return ""; // cycle detected
        return order;
    }
};
