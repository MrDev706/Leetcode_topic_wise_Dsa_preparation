//Binary search tree to greater sum tree
//LEETCODE: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

class Solution {
public:
    int total = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        bstToGst(root->right);
        root->val = total += root->val;
        bstToGst(root->left);
        return root;

    }
};