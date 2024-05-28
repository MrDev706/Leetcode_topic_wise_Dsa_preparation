


class Solution {
public:
vector<string> res;
    vector<string> generateParenthesis(int n) {
        
        helper( 0, 0, "", n);
        return res;

        
    }

    void helper(int l, int r, string curr, int n){
        if(r==n && l==n){
            res.push_back(curr);
        }
        if(l<n){
            helper( l+1, r, curr+'(', n);  
        }
        if(r<l){
            helper(l, r+1, curr+')', n);
        }
    }
};


