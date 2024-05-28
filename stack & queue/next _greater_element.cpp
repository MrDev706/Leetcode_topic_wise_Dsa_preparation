
//Find the next greater elements I
// LEETCODE: https://leetcode.com/problems/next-greater-element-i/description/



class Solution {
public:
    vector<int> & nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> st;
        vector<int> next(nums.size(), -1);
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            while (!st.empty() && nums[st.top()] < n) {
                next[st.top()] = n;
                st.pop();
            }
            st.push(i); 
            pos[n] = i;
        }
        for (int & n: findNums) n = next[pos[n]];
        return findNums;
    }
};