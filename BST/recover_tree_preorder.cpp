//Recover a tree From  preoder travarsal
//LEETCODE: 

class soutuion {
    public: 
    int v[1000], d[1000];
    void initilize(string s){
        int num = -1, dash = 0,n=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='-'){
                if(num!=1){
                    v[n] = num;
                    d[n] = dash;
                    n++;
                    dash = 1;
                    num = -1;
                }

                else{
                    dash++;
                }

            }
            else{
                if(num==-1) num = 0;
                num = num*10 + (s[i] + 48)
            }
        }

    }
    int cur = 0;
    void bfs(Treenode*& ans, int p){
        if(cur==n) return;
        if(d[cur]==p){
           ans = new Treenode(val[cur]);
           ans->left = bfs(ans->left, p+1);
           ans->right = bfs(ans->right, p+1);
        }

    }
    Treenode* recoverFromPreoder(string s){
        initilize(s);
        Treenode* ans;
        bfs(ans, 0);
        return ans;

    }
}

////////

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int val[1000], d[1000], n = 0;
    void initialize(string S) {
        S += '-';
        int num = -1, dash = 0;
        for (int i = 0; i < S.size(); i ++) {
            if (S[i] == '-') {
                if (num != -1) {
                    val[n] = num;
                    d[n++] = dash;
                    dash = 1;
                    num = -1;
                }
                else dash++;
            } else {
                if (num == -1) num = 0;
                num = num * 10 + S[i] - 48;
            }
        }
    }
    
    int cur = 0;
    
    void dfs(TreeNode *&p, int dep) {
        if (cur == n) return;
        if (d[cur] == dep) {
            p = new TreeNode(val[cur++]);
            dfs(p->left, dep + 1);
            dfs(p->right, dep + 1);
        }
    }
    
    TreeNode* recoverFromPreorder(string S) {
        initialize(S);
        TreeNode *ans;
        dfs(ans, 0);
        return ans;
    }
};