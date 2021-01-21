/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string token : tokens) {
            if(isdigit(token.back()))
                s.push(stoi(token));
            else {
                int sum = 0;
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                if(token == "+")
                    sum = num1 + num2;
                if(token == "-")
                    sum = num1 - num2;
                if(token == "*")
                    sum = num1 * num2;
                if(token == "/")
                    sum = num1 / num2;

                s.push(sum);
            }
        }

        return s.top();
    }
};
// @lc code=end

