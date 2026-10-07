class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

    bool backtrack(vector<vector<char>>& board){

        int n = board.size();
        int m = board[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j] == '.'){

                    for(char k = '1';k <= '9';k++){

                        if(isSafe(k,i,j,board)){
                            board[i][j] = k;

                            if(backtrack(board)){
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

    bool isSafe(char num,int row,int col,vector<vector<char>>& board){


        for(int i=0;i<9;i++){

            if(board[row][i] == num){
                return false;
            }

            if(board[i][col] == num){
                return false;
            }

            int subRow = 3 * (row/3) + (i/3);
            int subCol = 3 * (col/3) + (i%3);

            if(board[subRow][subCol] == num){
                return false;
            }
        }

        return true;
    }
};