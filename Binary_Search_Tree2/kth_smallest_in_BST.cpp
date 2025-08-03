class Solution {
    public:
        void get_k_smallest(TreeNode* &root,int &k,int &value){
                  if(!root || value!=-1) return;
                  get_k_smallest(root->left,k,value);
                  k--;
                  if(k==0){
                  value=root->val;
                  return;
                  }
                  get_k_smallest(root->right,k,value);
        }
        int kthSmallest(TreeNode* root, int k) {
            int value=-1;
            get_k_smallest(root,k,value);
            return value;
        }
    };

// for the follow up, we can use maxheap maintaining ele upto size k,
// the top ele of this heap will be the kth smallest ele,
// if any ele smaller to this is inserted, insert it in heap and return the top ele, maintaing the size of k,
// if any ele smaller to this is deleted, delete it from heap and we need to find the just greater ele from the tree for the top ele,and insert it in heap,
// any insertions and deletion of elements that are greater than top ele of heap will not be doing any changes in heap, just insert them in your original tree...  