/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    string letters[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string cur = "";
        solve(res, cur, digits, 0);
        return res;
    }

    void solve(vector<string>& res, string& cur, string& digits, int idx) {
        if(digits == "")
            return;

        int n = digits.size();
        if(cur.size() == n) {
            res.push_back(cur);
            return;
        }

        int num = digits[idx] - '0' - 1;
        string choices = letters[num];
        
        for(char c : choices) {
            cur += c;
            solve(res, cur, digits, idx+1);
            cur.pop_back();
        }
    }
};
// @lc code=end

