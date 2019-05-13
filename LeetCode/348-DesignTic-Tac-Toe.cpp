class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        rowCnt.resize(n, 0);
        colCnt.resize(n, 0);
        diagCnt     = 0;
        antiDiagCnt = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            if (row == col) ++ diagCnt;
            if (row == (n-1)-col) ++ antiDiagCnt;
            if (diagCnt >= n || antiDiagCnt >= n) return 1;
            ++ rowCnt[row];
            ++ colCnt[col];
            return (rowCnt[row] >= n || colCnt[col] >= n) ? 1 : 0;
        }
        else {
            if (row == col) -- diagCnt;
            if (row == (n-1)-col) -- antiDiagCnt;
            if (diagCnt <= -n || antiDiagCnt <= -n) return 2;  
            -- rowCnt[row];
            -- colCnt[col];
            return (rowCnt[row] <= -n || colCnt[col] <= -n) ? 2 : 0;
        }
    }
private:
    int n;
    vector<int> rowCnt;
    vector<int> colCnt;
    int diagCnt;
    int antiDiagCnt;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
