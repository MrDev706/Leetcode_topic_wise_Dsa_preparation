//Find the kth smallest element in a BST
//LEETCODE: https://leetcode.com/problems/kth-smallest-element-in-a-bst/


class Solution {
public:
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
        
    }


    void inorder(TreeNode* root, int& k){
        if(root==NULL) return;
        inorder(root->left, k);
        if(--k==0){
            ans = root->val;
            return;
        }
        inorder(right, k);
    }

}
