//LEETCODE: 79 : https://leetcode.com/problems/word-search/description/

class Solution {
public:
  bool dp[100][100] = {};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(dp[i][j]) return dp[i][j];
                    if(solve(board, i, j, 0, word)){
                        //cout<<i<<j<<endl;
                        return true;
                    }else{
                        continue;
                    }

                }
            }
        }
        return false;
        
    }
    bool solve(vector<vector<char>>& board, int i, int j, int w, string &word){
        
        if(w==word.size()) return true;
        if(i>=board.size() || j>=board[0].size() || board[i][j] == -1) return false;
        if(dp[i][j]) return dp[i][j];
        if(board[i][j]!=word[w]){
           
            return false;

        }else{
            
             //cout<<board[i][j]<<endl;
        int temp = board[i][j];
        board[i][j] = -1;

        bool x = solve(board, i+1, j, w+1, word);
        bool y = solve(board, i, j+1, w+1, word);
        bool v = solve(board, i, j-1, w+1, word);
        bool z = solve(board, i-1, j, w+1, word);
        board[i][j] = temp;
        return dp[i][j] = (x || y || v || z);

        }
        return false;
    }
};