//unique paths II


class Solution {
public:
    int arr[100][100] {};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return dfs(obstacleGrid, 0, 0);

        
    }

    int dfs(vector<vector<int>>& ob, int i, int j){
        //if(ob[i][j]==1) return 0;
        if(i>=ob.size() || j>= ob[0].size()) return 0;
        if(ob[i][j]==1) return 0;
        
        if(i==ob.size()-1 && j==ob[0].size()-1) return 1;
         if(arr[i][j]) return arr[i][j];
        
        

        return arr[i][j] = dfs(ob, i+1, j) + dfs(ob, i, j+1);

    }
};