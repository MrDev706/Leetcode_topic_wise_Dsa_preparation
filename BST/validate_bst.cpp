//Leetcode: 98. Validate Binary Search Tree



class Solution {
public:
   bool helper(TreeNode* root, long low, long high){
       if(root==NULL){
           return true;
       }
       if(root->val>low && root->val<high){
           return helper(root->left, low, root->val) && helper(root->right, root->val, high);
       }else{
           return false;
       }
   }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};