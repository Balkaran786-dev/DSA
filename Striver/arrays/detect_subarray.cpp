class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        for (int i = 0; i + m < arr.size(); i++) {
            count = arr[i] == arr[i + m] ? count + 1 : 0;
            if (count == (k - 1) * m)  //k-1 beacuse jab humne match kiya k-1 times, ek jiske sath match kiya voh bhi toh equal hai na...
                return true;
        }
        return false;
    }
};