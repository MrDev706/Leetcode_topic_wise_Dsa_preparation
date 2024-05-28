//LEETCODE: https://leetcode.com/problems/range-sum-of-bst/description/
//Range sum bst from lower or higher value

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
        return (root->val>=L && root->val<=R ? root->val:0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        
    }
};