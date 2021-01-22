/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m;

        for(int a : A) {
            for(int b : B) {
                int sum = a + b;
                m[-sum] ++;
            }
        }

        for(int c : C) {
            for(int d : D) {
                int sum = c + d;
                res += m[sum];
            }
        }

        return res;
    }
};
// @lc code=end

