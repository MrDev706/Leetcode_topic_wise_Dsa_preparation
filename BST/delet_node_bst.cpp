//Delete a Node in Bst
//LEETCODE:  https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {

    public: 
    deleteNode(TreeNode* root, int k){
        if(root){
            if(root->val>k) root->left = deleteNode(root->left);
            else if(root->val<k) root->right = deleteNode(root->right);
            else {
                if(!root->left && !root->right) return NULL;
                if(!root->left || !root->right) return root->left?root->left:root->right;

                TreeNode* temp = root->left;
                while(!temp->right==NULL) temp = temp->right;
                root->val = temp->Val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
    
      



}