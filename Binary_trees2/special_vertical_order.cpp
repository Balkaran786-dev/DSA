#define pp pair<int,int>
class Solution {
public:
    static bool cmp(pp a1,pp a2){  
        if(a1.second==a2.second){
            return a1.first<a2.first;
        }
        return a1.second<a2.second; // matlab agr row same nhi hai toh jo column mein upper hai, uska row shota i hona chahiye.
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pp>> mp;
        queue<pair<TreeNode*,int>> qu;

        qu.push({root,0});
        mp[0].push_back({root->val,0});
        int i=1;  //for row track
        while(!qu.empty()){
            int nodes_at_same_level=qu.size();
            while(nodes_at_same_level--){
                auto curr=qu.front();
                qu.pop();

                if(curr.first->left){
                    mp[curr.second-1].push_back({curr.first->left->val,i});
                    qu.push({curr.first->left,curr.second-1});
                }
                if(curr.first->right){
                    mp[curr.second+1].push_back({curr.first->right->val,i});
                    qu.push({curr.first->right,curr.second+1});
                }
            }
            i++;  //for row track
        }

        vector<vector<int>> vec;
        vector<int> temp;

        for(auto col:mp){
            sort(col.second.begin(),col.second.end(),cmp);
            for(auto node:col.second){
               temp.push_back(node.first);
            }
            vec.push_back(temp);
            temp.clear();
        }
        return vec;
    }
};