//LEETCODE: https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/


class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        solve(root, 0);
        return ret;
    }
    void solve(TreeNode* root, int level)
    {   if(root==NULL) return ;
        if(ret.size()<level+1) ret.resize(level+1);
        ret[level].push(root->val);
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
};


//queue approach

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};




