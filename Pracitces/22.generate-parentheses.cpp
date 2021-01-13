/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void backTrack(vector<string> &res, string curStr, int open, int close) {
        if(open == 0 && close == 0) {
            res.push_back(curStr);
            return;
        }

        if(close > 0) {
            backTrack(res, curStr + ")", open, close-1);
        }
        if(open > 0) {
            backTrack(res, curStr + "(", open-1, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        backTrack(res, str, n, 0);
        return res;
    }
};
// @lc code=end

