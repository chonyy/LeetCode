/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        int start = 0;
        for(int i = 0; i < n; i ++) {
            int cur = max(getLen(i, i, n, s), getLen(i, i+1, n, s));
            if(cur > len) {
                len = cur;
                start = i - (len-1) / 2;
            }
        }
        return s.substr(start, len);
    }

    int getLen(int l, int r, int n, string s) {
        while(l >=0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
        }
        return r-l-1;
    }
};
// @lc code=end

