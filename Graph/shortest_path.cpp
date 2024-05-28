//LEETCODE: https://leetcode.com/problems/shortest-bridge/description/
//facebook, amazon

class Solution {
public:
      int n, ans=0;
     queue<vector<int>> q;
    vector<vector<bool>> vis;
    vector<int> di= {-1,0,1,0} , dj= {0,1,0,-1};
    bool isValid(int i, int j){
        return (i>=0 && j>=0 && i<n && j<n);
    }
    void dfs(int i, int j, vector<vector<int>>& grid){
        for(int k=0; k<4; k++){
            int ii = i + di[k], jj = j + dj[k];
            if(isValid(ii, jj) && grid[ii][jj]==1){
                q.push({ii, jj});
                vis[ii][jj] = true;
                grid[ii][jj] = 0;
                dfs(ii, jj, grid);
            }
        }

    }
 
    int shortestBridge(vector<vector<int>>& grid){
        n = grid.size();
        vis.resize(n, vector<bool>(n, false));
        bool done = false;

        for(int i=0; i<n; i++){
            if(done==true) break;

            for(int j=0; j<n; j++){
                if(done) break;
                if(grid[i][j]==1){
                    q.push({i, j});
                    vis[i][j] = true;
                    grid[i][j] = 0;
                    dfs(i, j, grid);
                    done = true;
                    
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int i = q.front()[0], j = q.front()[1];
                q.pop();
                for(int k=0;k<4; k++){
                    int ii = i + di[k], jj = j+dj[k];
                    if(isValid(ii, jj) && vis[ii][jj] == false){
                        if(grid[ii][jj] == 1) return ans;

                        q.push({ii, jj});
                        vis[ii][jj] = true;
                    }
                }
            }
            ans++;
           
        }
         return ans;
    }
    
};