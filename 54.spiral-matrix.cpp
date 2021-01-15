/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        int rowStart = 0, colStart = 0;
        int rowEnd = m - 1, colEnd = n - 1;

        cout << rowStart << rowEnd << endl;
        cout << colStart << colEnd << endl;
        cout << endl;
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int i = colStart; i <= colEnd; i ++) {
                res.push_back(matrix[rowStart][i]);
            }
            rowStart ++;

            for(int i = rowStart; i <= rowEnd; i ++) {
                res.push_back(matrix[i][colEnd]);
            }
            colEnd --;

            if(rowStart <= rowEnd) {
                for(int i = colEnd; i >= colStart; i --) {
                    res.push_back(matrix[rowEnd][i]);
                }
                rowEnd --;
            }

            if(colStart <= colEnd) {
                for(int i = rowEnd; i >= rowStart; i --) {
                    res.push_back(matrix[i][colStart]);
                }
                colStart ++;
            }

            cout << rowStart << rowEnd << endl;
            cout << colStart << colEnd << endl;
            cout << endl;
        } 
        return res;
    }
};
// @lc code=end

