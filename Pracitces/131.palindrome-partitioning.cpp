/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<string>> &res, vector<string> &str, string &s, int index) {
        if(index == s.size()) {
            res.push_back(str);
            return;
        }     

        for(int i = index; i < s.size(); i ++) {
            if(isPalindrome(s, index, i)) {
                str.push_back(s.substr(index, i-index+1));
                dfs(res, str, s, i+1);
                str.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> str;
        dfs(res, str, s, 0);
        return res;
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start ++] != s[end --])
                return false;
        }
        return true;
    }
};
// @lc code=end

