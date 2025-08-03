class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n+1, 0);
        for (auto& shift : shifts) {
            diff[shift[0]] += (shift[2] == 1) ? 1 : -1;
            diff[shift[1] + 1] += (shift[2] == 1) ? -1 : 1;
        }
        
        int shiftSum = 0;
        for (int i = 0; i < n; ++i) {
            cout << diff[i] << endl;
            shiftSum = (shiftSum + diff[i]) % 26;  //prefix sum , it can be as high and as low as anything, so to keep it in the bounds of -25 to 25, we did modulo with 26
            if (shiftSum < 0) shiftSum += 26;    //to make the transition in forward direction, we can do it by adding 26, for ex:- we have -1 for a to convert to z , we can do that by adding 25 in 'a',
            s[i] = 'a' + (s[i] - 'a' + shiftSum) % 26;

            /*
            if shiftsum add krne ke baad bhi ans is coming in the bounds,
            toh you can assume ki 26 ka koi farak nhi pdega, hence 'a' + s[i] + 'a' + shiftsum, s[i] + shiftsum and we get ans.
            you can visually see this, 
            */
        }
        return s;
    }
};