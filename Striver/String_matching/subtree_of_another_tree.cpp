class Solution {
public:
    void preorder(TreeNode* root, string &s) {
        if (root == nullptr) {
            s += ",#";  // null marker to encode structure
            return;
        }
        s += "," + to_string(root->val);
        preorder(root->left, s);
        preorder(root->right, s);
    }

    bool KMP(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();

        // Build LPS array
        vector<int> LPS(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = LPS[len - 1];
                else
                    LPS[i++] = 0;
            }
        }

        // Match pattern in text
        i = 0;
        int j = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
                if (j == m) return true;
            } else {
                if (j != 0)
                    j = LPS[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1 = "", str2 = "";
        preorder(root, str1);
        preorder(subRoot, str2);

        return KMP(str1, str2);
    }
};
