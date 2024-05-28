//LEETCODE: 78. Subsets

class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        vector<int> sub;
        res.push_back(sub);
        solve(nums, l, r, sub);
        return res;
        
    }

    void solve(vector<int>& nums, int l, int r, vector<int>&sub){
        if(l>r) {
            //res.push_back(sub);
            return;

        }   
            
            sub.push_back(nums[l]);
            res.push_back(sub);
            solve(nums, l+1, r, sub);
            sub.pop_back();
            solve(nums, l+1, r, sub);

    }
};