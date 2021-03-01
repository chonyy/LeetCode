/*
 * @lc app=leetcode id=562 lang=cpp
 *
 * [562] Longest Line of Consecutive One in Matrix
 */

// @lc code=start
class Solution {
public:
    int row;
    int col;
    int longestLine(vector<vector<int>>& M) {
        row = M.size();
        if(row == 0)
            return 0;
        col = M[0].size();
        int dp[row][col][4];
        int res = 0;

        // 0: verical
        // 1: horizontal
        // 2: diagonal
        // 3: anti-diagonal

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(M[i][j] == 0) {
                    for(int k = 0; k < 4; k ++) {
                        dp[i][j][k] = 0;
                    }
                    continue;
                }

                // Initialization
                for(int k = 0; k < 4; k ++) {
                    dp[i][j][k] = 1;
                }

                // verical
                if(i > 0) {
                    dp[i][j][0] += dp[i-1][j][0];
                }
                // horizontal
                if(j > 0) {
                    dp[i][j][1] += dp[i][j-1][1];
                }
                // diagonal
                if(i > 0 && j > 0) {
                    dp[i][j][2] += dp[i-1][j-1][2];
                }
                // antidiagonal
                if(i > 0 && j < col-1) {
                    dp[i][j][3] += dp[i-1][j+1][3];
                }

                res = max(res, max(dp[i][j][0], dp[i][j][1]));
                res = max(res, max(dp[i][j][2], dp[i][j][3]));

                cout << i << j << endl;
                cout << res << endl;
                // cout << "vertical" << dp[i][j][0] << endl;
                // cout << "horizontal" << dp[i][j][1] << endl;
                // cout << "diagonal" << dp[i][j][2] << endl;
                // cout << "antidiagoonal" << dp[i][j][3] << endl;
            }
        }

        return res;
    }
};
// @lc code=end

