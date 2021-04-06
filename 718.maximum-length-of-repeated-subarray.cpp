/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        const int m = B.size();

        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        int res = 0;

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(A[i-1] == B[j-1]) {
                    cur[j] = prev[j-1] + 1;
                    res = max(res, cur[j]);
                }
                else {
                    cur[j] = 0;
                }
            }
            prev = cur;
        } 

        return res;
    }
};
// @lc code=end

