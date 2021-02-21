/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1; i <= numRows; i ++) {
            int num = i;
            vector<int> row(num);
            row[0] = 1;
            row[num-1] = 1;
            if(i > 1) {
                vector<int> prevRow = res.back();
                for(int j = 1; j < num-1; j ++) {
                    row[j] = prevRow[j-1] + prevRow[j];
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end

