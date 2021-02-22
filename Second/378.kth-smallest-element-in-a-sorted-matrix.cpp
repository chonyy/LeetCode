/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};
// @lc code=end

