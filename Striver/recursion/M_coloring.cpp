// Mine approach:-
/*
for every vertex , one by one , you give them all colors,
like for 1st vertex, we try first color by checking if any of its adjacent 
node is not having that same color, if this color cannot be given to this vertex, we try to give 
any other color, once we give it a color, we shift to the next vertex and try all possible colors again,
if at any vertex, we are not able to give any color to it,we return false,
if we reach the vertex == n(since we have vertex from 0 to n-1), we return true, that means we r 
able to give all the vertixes a color satisfying the given condition.

data structures:-
1. hashmap -> (vertex,color)
2. vector of list to store graph.
*/

