


class Solution {
public:

    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        
        return solve(n, dp);

  
    }
    int solve(int n, vector<int>&dp){
        if(n==0) return 1; 
        if(n<0) return 0;
        if(dp[n] > -1) return dp[n];
        int x = solve(n-1, dp);
        int y = solve(n-2, dp);
        dp[n] = x+y;
        return x+y;
    }
};


