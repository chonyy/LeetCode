/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(int toPush : pushed) {
            pushed[i++] = toPush;
            while(i != 0 && pushed[i-1] == popped[j]) {
                i --;
                j ++;
            }
        }

        return i == 0;
    }
};
// @lc code=end

