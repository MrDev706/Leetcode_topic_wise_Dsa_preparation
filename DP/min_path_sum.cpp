//leetocde: https://leetcode.com/problems/minimum-path-sum/description/


class Solution {
public:
    int dp[1000][1000] = {};
    int minPathSum(vector<vector<int>>& grid) {
        
        return dfs(grid, 0, 0);
        
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        
        if(i>grid.size()-1 || j>grid[0].size()-1) return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]) return  dp[i][j];
        int x = min(dfs(grid, i+1, j), dfs(grid, i, j+1));
        dp[i][j] = grid[i][j] + x;
         

        return  dp[i][j];
    }
};