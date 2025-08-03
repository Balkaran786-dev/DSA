
class Solution {
public:
    int compareFromBack(const std::string& a, const std::string& b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 && j >= 0) {
            if (a[i] < b[j])
                return -1; // a is smaller
            if (a[i] > b[j])
                return 1; // a is bigger
            i--;
            j--;
        }

        // If one string is shorter but all characters matched till now
        if (i < 0 && j >= 0)
            return -1; // a is shorter => smaller
        if (j < 0 && i >= 0)
            return 1; // b is shorter => a is bigger
        return 0;     // Equal
    }
    void fun(TreeNode* root, string& smallest, string& temp) {
        if (!root)
            return;

        temp.push_back('a' + root->val);
        if (!root->left && !root->right) {
           int res=compareFromBack(smallest,temp);
           if(res==1) smallest=temp;
           temp.pop_back();
           return;
        }

        fun(root->left,smallest,temp);
        fun(root->right,smallest,temp);
        temp.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string smallest = "~";
        string temp = "";
        fun(root, smallest, temp);
        reverse(smallest.begin(),smallest.end());
        return smallest;
    }
};