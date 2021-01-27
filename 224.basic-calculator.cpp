/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign = '+';
        int n = s.size();
        int res = 0, tmp = 0;

        for(int i = 0; i < n; i ++) {
            int curChar = s[i];
            if(isdigit(curChar))
                tmp = tmp * 10 + curChar - '0';
            if((!isdigit(curChar) && !isspace(curChar)) || i == n - 1) {
                if(sign == '-') {
                    stk.push(-tmp);
                }
                else if(sign == '+') {
                    stk.push(tmp);
                }
                else {
                    int num ;
                    if(sign == '*') {
                        num = stk.top() * tmp;
                    }
                    else {
                        num = stk.top() / tmp;
                    }
                    stk.pop();
                    stk.push(num);
                }
                sign = curChar;
                tmp = 0;                
            }
        }

        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

