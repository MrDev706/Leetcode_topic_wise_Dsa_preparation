//LEETCODE: 200. Number of Islands

class Solution {
public:
    void Dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return ;
        }
        if(grid[i][j]=='2' || grid[i][j]=='0'){
            return ;
        }
        grid[i][j] = '2';

        Dfs(grid, i, j+1);
        Dfs(grid, i, j-1);
        Dfs(grid, i+1, j);
        Dfs(grid, i-1, j);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), s = grid[0].size(), isLands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<s; j++){
                if(grid[i][j]=='1'){
                    Dfs(grid, i, j);
                    isLands++;
                }
            }
        }
        return isLands;


        
    }
};