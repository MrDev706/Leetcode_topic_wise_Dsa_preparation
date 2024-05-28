//LEETCODE COMBINATON SUM I


class Solution {
public:
 vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> v;
        solve(cand, target, 0, v);
        return ans;
    }

    void solve(vector<int>& cand, int target, int p, vector<int>& v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=p; i<cand.size(); i++){
            v.push_back(cand[i]);
            solve(cand, target-cand[i], i, v);
            v.pop_back();

        }
    }
};