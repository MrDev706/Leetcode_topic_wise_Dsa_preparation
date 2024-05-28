//Subarray product less than k;
//LEETCODE: 


class Solution {
public:
    int cnt = 0;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1, start=0;
        for(int i=0; i<nums.size(); i++){
            prod *= nums[i];
            while(start<=i && prod >=k){
                prod /= nums[start++];
            }
            cnt += i-start + 1;
        }
        return cnt;

        
    }
};