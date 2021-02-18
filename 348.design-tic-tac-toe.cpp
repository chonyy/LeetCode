/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start
class TicTacToe {
    vector<int> row;
    vector<int> col;
    int size;
    int diagonal;
    int antidiagonal;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        row = vector<int>(n);
        col = vector<int>(n);
        diagonal = 0;
        antidiagonal = 0;
        size = n;
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
        int toAdd = player == 1 ? 1 : -1;

        this->row[row] += toAdd;
        this->col[col] += toAdd;
        if(row == col)
            diagonal += toAdd;
        if(row + col == size-1)
            antidiagonal += toAdd;

        if(abs(this->row[row]) == size || abs(this->col[col]) == size || abs(diagonal) == size || abs(antidiagonal) == size)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
// @lc code=end

