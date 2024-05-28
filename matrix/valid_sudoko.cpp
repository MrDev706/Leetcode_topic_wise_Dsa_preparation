class solution {
    public: 
    bool isValidsudoko(vector<vector<char>>& board, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<9; j++){
                if(!valid(board, i, j)){
                    return false;
                }
            }
        }

    }
    bool valid(vector<vector<char>>& board, int rows, int col, int n ){
        return validRows(board, n, rows) && validColums(board, n, col)
    }

    bool validRows(vector<vector<char>>& board, int n, int rows){
        set<int> st;
        for(int i=0; i<n; i++){
            if(st.find(board[rows][i])!= st.end()){
                return false;
            }
            if(board[rows][i] !="."){
                st.insert(board[rows][i]);
            }
        }
        return true;

    }
    bool validColums(vector<vector<char>>& board, int n, int col){
        set<int> st;

        for(int i=0; i<n; i++){
            if(st.find(board[i][col]) != st.end()){
                return false;
            }
            if(board[i][col]!='.'){
                st.insert(board[i][col]){
                }
            }
        }
        return true;
    }

}