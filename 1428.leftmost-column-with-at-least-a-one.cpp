/*
 * @lc app=leetcode id=1428 lang=cpp
 *
 * [1428] Leftmost Column with at Least a One
 */

// @lc code=start
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        int curRow = 0, curCol = cols - 1;
        int res = -1;

        while(curRow < rows && curCol >= 0) {
            if(binaryMatrix.get(curRow, curCol)) {
                res = curCol;
                curCol --;
            }
            else {
                curRow ++;
            }
        }
        return res;
    }
};
// @lc code=end

