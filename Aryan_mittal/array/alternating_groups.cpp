//For each tile, check that the previous and the next tile have different colors from that tile or not.
// check for the first and last tile separately...

class Solution {
  int numberOfAlternatingGroups(List<int> colors) {
    int last = colors.last;
    int first = colors.first;

    int count = 0;
    for(int i = 1; i < colors.length-1; i++){
        if(colors[i-1] == colors[i+1] && colors[i] != colors[i-1]){
            count++;
        }
    }

    if(colors[colors.length-2] == first && last != first){
        count++;
    }

    if(colors[1] == colors.last && colors[1] != first){
        count++;
    }

    return count;
  }
}