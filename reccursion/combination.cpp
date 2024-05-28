//Leetcode 77: https://leetcode.com/problems/combinations/description/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        solve(v, n, k,  1);
        return ans;
    }
    void solve(vector<int>&v, int n, int k, int cnt){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        if(v.size()>k){
            return;

        }
        for(int i=cnt; i<=n; i++){
            v.push_back(i);
            solve(v, n, k , i +1);
            v.pop_back();

        }
    }
};