/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int curMax = 0;

        vector<vector<int>> res(row, vector<int>(col, 0));

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(i == 0 || j == 0) {
                    res[i][j] = matrix[i][j] - '0';
                    curMax = max(curMax, res[i][j]);
                }
                else {
                    if(matrix[i][j] - '0') {
                        res[i][j] = min(min(res[i-1][j-1], res[i-1][j]), res[i][j-1])+1;
                        curMax = max(curMax, res[i][j]);
                    }
                }
                cout << i << j << endl;
                cout << res[i][j] << endl;
            }
        }

        return curMax * curMax;
    }
};
// @lc code=end

