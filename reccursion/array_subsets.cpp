//LEETCODE: https://leetcode.com/problems/subsets/submissions/868831357/


class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        vector<int> sub;

        solve(nums, l, r, sub);
        return res;
        
    }

    void solve(vector<int>& nums, int l, int r, vector<int>&sub){
        res.push_back(sub);
        for(int i=l; i<=r; i++){
            sub.push_back(nums[i]);
            solve(nums, i+1, r, sub);
            sub.pop_back();
        }
    }
};

//RECURSIVE AND BACLTRACKING APPOARCH
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
            return;
        }   
            sub.push_back(nums[l]);
            res.push_back(sub);
            solve(nums, l+1, r, sub);
            sub.pop_back();
            solve(nums, l+1, r, sub);

    }
};