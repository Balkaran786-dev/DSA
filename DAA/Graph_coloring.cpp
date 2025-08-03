#include <bits/stdc++.h>
using namespace std;

bool canPlace(int v, vector<vector<int>>& mat, vector<int>& shades, int clr) {
    for (int i = 0; i < mat.size(); ++i) {
        if (mat[v][i] && shades[i] == clr)
            return false;
    }
    return true;
}

bool assignColors(int total, int limit, vector<int>& shades, int current) {
    if (current == total) return true;

    for (int col = 1; col <= limit; ++col) {
        if (canPlace(current, mat, shades, col)) {
            shades[current] = col;
            if (assignColors(total, limit, shades, current + 1))
                return true;
            shades[current] = 0;
        }
    }
    return false;
}

int main() {
    int nodes, palette;
    cin >> nodes;
    vector<vector<int>> mat(nodes, vector<int>(nodes));
    for (int i = 0; i < nodes; ++i)
        for (int j = 0; j < nodes; ++j)
            cin >> mat[i][j];

    cin >> palette;

    vector<int> shades(nodes, 0);

    if (assignColors(nodes, palette, shades, 0)) {
        for (int i = 0; i < nodes; ++i)
            cout << i << " " << shades[i] << "\n";
    } else {
        cout << "Not Possible\n";
    }

    return 0;
}
