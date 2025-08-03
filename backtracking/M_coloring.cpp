// for all possible coloring combinations, use can just use backtracking,..


class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        //first we need to make a adjacency list
        //then,start from 0th vertex,start putting color,
        // and store the color of the vertex in the marked vector
        // and then move to next vertex, check all possible colors from 1 to m,
        // put that color, that is not given to any adjacent vertex 
        // like this, if you are able to successfully give color to the last vertex
        // return true,
        // else return false, and backtrack and go to other ways.
    }
};

// for M-coloring optimisation problem,
// you can use the above code but with binary search on search space l=1 to l=n, n=number of nodes// maximum number of color can be equal to n...
