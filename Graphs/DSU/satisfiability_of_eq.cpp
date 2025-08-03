class Solution {
public:
    int Find(vector<int>& par, int x) {
        return par[x] = (par[x] == x ? x : Find(par, par[x]));
    }
    void Union(vector<int>& par, vector<int>& rank, int a, int b) {
        a = Find(par, a);
        b = Find(par, b);
        if (rank[a] <= rank[b]) {
            par[a] = b;
            rank[b]++;
        } else {
            par[b] = a;
            rank[a]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int> not_equal(26, -1);
        vector<int> par(26);
        vector<int> rank(26, 1);
        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }

        vector<string> hold;
        for (int i = 0; i < n; i++) {
            string str = equations[i];
            if (str[1] == '!')
                hold.push_back(str);
            else {
                Union(par, rank, str[0] - 'a', str[3] - 'a');
            }
        }
        int m=hold.size();
        if(m==0) return true;
 
        for(int i=0;i<m;i++){
            string str = hold[i];
            char ch1=str[0],ch2 = str[3];
            if(Find(par,ch1-'a')==Find(par,ch2-'a')) return false;
        }
        return true;
    }
};