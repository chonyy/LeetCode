/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(i > j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

