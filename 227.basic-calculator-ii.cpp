/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        char sign = '+';
        long temp = 0;
        stack<int> stk;

        for(int i = 0; i < n; i ++) {
            char curChar = s[i];
            if(isdigit(curChar)) {
                temp = temp * 10 + curChar - '0';
            }
            if((!isdigit(curChar) && !isspace(curChar)) || i == n-1) {
                cout << curChar << sign << endl;
                if(sign == '+')
                    stk.push(temp);
                else if(sign == '-')
                    stk.push(-temp);
                else {
                    long res;
                    if(sign == '*') {
                        res = stk.top() * temp;
                    }
                    else {
                        res = stk.top() / temp;
                    }
                    stk.pop();
                    stk.push(res);
                }
                temp = 0;
                sign = curChar;
            }
        }

        int sum = 0;
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }

        return sum;
    }
};
// @lc code=end

