//LEETCODE:https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution {
public:
int numTrees(int n) 
{
    vector<int> trees(n + 1, 0);
    
    trees[0] = 1;
    trees[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            trees[i] += trees[j] * trees[i - j - 1];
    
    return trees[n];
}
};
