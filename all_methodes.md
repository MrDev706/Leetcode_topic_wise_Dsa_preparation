









***Backtracking solve***

Pick a starting point.
while(Problem is not solved)
    For each path from the starting point.
        check if selected path is safe, if yes select it
        and make recursive call to rest of the problem
        before which undo the current move.
    End For
If none of the move works out, return false, NO SOLUTON.

**************************************************************


************************SET METHODES*********
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v1, v2;
    set<int> s1(begin(nums1), end(nums1)), s2(begin(nums2), end(nums2));
    set_difference(begin(s1), end(s1), begin(s2), end(s2), back_inserter(v1));
    set_difference(begin(s2), end(s2), begin(s1), end(s1), back_inserter(v2));
    return {v1, v2};
}
};


*************************************

