/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        int n = s.size();

        for(int i = 0; i < n; i ++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                if(stk.empty()) {
                    s[i] = '*';
                }
                else {
                    stk.pop();
                }
            }
        }

        while(!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};
// @lc code=end

