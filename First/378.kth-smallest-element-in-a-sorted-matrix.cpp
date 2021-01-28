/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        priority_queue<int, vector<int>> maxHeap;

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(maxHeap.size() < k)
                    maxHeap.push(matrix[i][j]);

                else {
                    if(matrix[i][j] < maxHeap.top()) {
                        maxHeap.pop();
                        maxHeap.push(matrix[i][j]);
                    }
                }
            }            
        }
        return maxHeap.top();
    }
};
// @lc code=end

