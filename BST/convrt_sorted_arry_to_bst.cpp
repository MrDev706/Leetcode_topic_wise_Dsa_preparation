//Convert a sorted array to Binary search Tree
//LEETCODE: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
        
    }
    TreeNode * helper(vector<int>&nums, int s, int e){
        if(s>e){
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = helper(nums, s, mid-1);
        temp->right = helper(nums, mid+1, e);
        return temp;
    }
};