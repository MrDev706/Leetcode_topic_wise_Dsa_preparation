LEETCODE: 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<1){
            return 0;
        }
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            sum = max(0, sum);
        }
        return maxi;
    }
};

