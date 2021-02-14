/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string token : tokens) {
            if(isdigit(token.back())) {
                stk.push(stoi(token));
            }
            else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                cout << op1 << " " << op2 << " " << token << endl;
                if(token == "+") {
                    stk.push(op1 + op2);
                }
                if(token == "-") {
                    stk.push(op1 - op2);
                }
                if(token == "*") {
                    stk.push(op1 * op2);
                }
                if(token == "/") {
                    stk.push(op1 / op2);
                }
            }
        }

        return stk.top();
    }
};
// @lc code=end

