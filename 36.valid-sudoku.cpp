/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedRow[9][9] = {0}, usedCol[9][9] = {0}, usedBox[9][9] = {0}; 

        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                int num = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if(board[i][j] != '.') {
                    if(usedRow[i][num] || usedCol[j][num] || usedBox[k][num])
                        return false;
                    usedRow[i][num] = 1;
                    usedCol[j][num] = 1;
                    usedBox[k][num] = 1;
                }
            }
        }
        return true;
    }
};
// @lc code=end

