//LEETCODE: https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN, minInc = 1, maxInc = 1;
        for(auto n : nums) {
            int t1 = minInc * n;
            int t2 = maxInc * n;
            maxInc = max(n, max(t1, t2));
            minInc = min(n, min(t1, t2));
            maxProd = max(maxInc, maxProd);
        }
        return maxProd;
    }
};





