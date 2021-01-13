/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;
        backTrack(res, digits, str, 0);
        return res;
    }

    void backTrack(vector<string> &res, string digits, string &str, int index) {
        if(digits.empty()) return;
        if(index == digits.size()) {
            res.push_back(str);
            return;
        }

        int num = digits[index] - '0';
        string candidate = v[num];

        if(candidate.length() == 0) return;

        for(int i = 0; i < candidate.length(); i ++) {
            str.push_back(candidate[i]);
            backTrack(res, digits, str, index+1);
            str.pop_back();
        }
    }
};
// @lc code=end

