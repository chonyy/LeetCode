/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c : s) {
            if(c == '(')
                stk.push(')');
            else if(c == '[')
                stk.push(']');
            else if(c == '{')
                stk.push('}');
            else {
                if(stk.empty())
                    return false;
                if(c != stk.top())
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

