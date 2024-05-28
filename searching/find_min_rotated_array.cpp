//Find minimum in rotated sorted array
//LEETCODE: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/




class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid, res=INT_MAX;
        while(l<=r) {
            mid = (l+r)/2; 
            res = min(res, nums[mid]);
            if(nums[l] <= nums[mid]) {
                if(nums[l] <= nums[r])
                    r = mid-1;
                else 
                    l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return res;
    }
}; 