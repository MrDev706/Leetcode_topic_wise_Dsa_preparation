//LEETCODE COMBINATION SUM II

class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& cd, int target) {
        vector<int> v;
        sort(cd.begin(), cd.end());

        solve(cd, target, v, 0);
        return ans;
        
    }
    void solve(vector<int>& cd, int target, vector<int>& v, int p){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=p; i<cd.size(); i++){
            if( i!=p && cd[i] == cd[i-1]){
                continue;
            }
            v.push_back(cd[i]);
            solve(cd, target-cd[i], v, i+1);
            v.pop_back();
        }

    }

};