/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        stack<pair<char, int>> stk;

        for(char c : s) {
            if(stk.empty() || stk.top().first != c) {
                stk.push({c, 1});
            }
            else if(++ stk.top().second == k)
                stk.pop();
        }

        while(!stk.empty()) {
            res.append(stk.top().second, stk.top().first);
            stk.pop();
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

