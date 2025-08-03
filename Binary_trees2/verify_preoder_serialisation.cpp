class Solution {
public:
    // every non null node create two vacancies,
    // every null node doesn't create any vacanies,
    // we maintain, count if vacanices,
    // Initially, it is 1, beacuse at least the size of string is 1, so there
    // must be one node present, when we encounter a non null node, first of
    // all, we reduce the vacancies by 1, then we add 2 to it, when we encounter
    // a null node, we just reduce -1, at any time, if the vacancies get
    // negative, we abort the process, or if at the end of string, the vacancies
    // need to be just zero.

    bool isValidSerialization(string preorder) {
        int slots = 1; // Initial slot for root
        int n = preorder.size();

        for (int i = 0; i < n;) {
            // If current char is comma, skip
            if (preorder[i] == ',') {
                i++;
                continue;
            }

            // Read the next token (either a number or '#')
            if (preorder[i] == '#') {
                slots--; // null node consumes 1 slot
                if(slots<0) return false;
                i++;
            } else {
                // Read number (could be multiple digits)
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                slots--;    // real node consumes 1 slot
                if(slots<0) return false;
                slots += 2; // and adds 2 new child slots
            }
        }

        return slots == 0;
    }
};