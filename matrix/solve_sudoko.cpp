//LEETCODE: 37. Sudoku Solver

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, char k){
        for(int s=0; s<9; s++){
            if(board[s][j]==k){
                return false;
            }
            if(board[i][s]==k){
                return false;
            }
             if(board[3*(i/3)+s/3][3*(j/3)+s%3]==k)
            {
                return false;
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board){
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char k='1'; k<='9'; k++){
                        
                        if(isValid(board, i, j, k)){
                            board[i][j] = k;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';

                        }
                    }
                    return false;
                }
                
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
        
    }
};