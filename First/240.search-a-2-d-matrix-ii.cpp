/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(m == 0 || n == 0) return false;

        int row = 0;
        int col = n - 1;

        while(col >= 0 && row < m) {
            if(matrix[row][col] == target) return true;
            else if(target > matrix[row][col]) {
                row ++;
                col = n - 1;
            }
            else{
                col --;
            }
        }
        return false;
    }
};
// @lc code=end

