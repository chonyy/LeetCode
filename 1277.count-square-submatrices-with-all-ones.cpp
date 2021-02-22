/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int result = 0;

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(i == 0 || j == 0) {
                    result += matrix[i][j];
                    continue;
                }

                else if(matrix[i][j]){
                    matrix[i][j] = min(min(matrix[i][j-1], matrix[i-1][j]), matrix[i-1][j-1]) + 1;
                    cout << i << j << matrix[i][j] << endl;
                    result += matrix[i][j];
                }
            }
        }

        return result;
    }
};
// @lc code=end

