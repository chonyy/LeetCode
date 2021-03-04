/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int curMin = min(check(A[0], A, B), check(B[0], A, B));
        curMin = min(curMin, check(A[0], B, A));
        curMin = min(curMin, check(B[0], B, A));

        return curMin == INT_MAX ? -1 : curMin;
    }

    int check(int target, vector<int>& A, vector<int>& B) {
        int n = A.size();
        int swaps = 0;
        for(int i = 0; i < n; i ++) {
            if(A[i] != target && B[i] != target)
                return INT_MAX;
            else if(A[i] != target)
                swaps ++;
        }
        return swaps;
    }
};
// @lc code=end

