//why only tries is done upto 1,
// The worst case is when b starts somewhere in the middle of one repetition of a, and ends in the next repetition.
// So, even if a is repeated enough to cover b in length, we still need one more repetition to complete the overlap.



class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = b.size();

        // Form LPS array
        vector<int> LPS(m);
        LPS[0] = 0;
        int len = 0;
        int i = 1;
        while (i < m) {
            if (b[len] == b[i]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        int rep = 1;
        string temp = a;
        while (a.size() < b.size()) {
            a += temp;
            rep++;
        }

        // Try matching now, and up to one more repeat
        for (int tries = 0; tries <= 1; ++tries) {
            i = 0;
            int j = 0;
            while (i < a.size()) {
                if (b[j] == a[i]) {
                    i++;
                    j++;
                    if (j == m) {
                        return rep;
                    }
                } else {
                    if (j != 0) {
                        j = LPS[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            a += temp;
            rep++;
        }
        return -1;
    }
};
