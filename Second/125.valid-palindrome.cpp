/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) 
            return true;

        int end = s.size() - 1;
        int start = 0;

        while(start < end) {
            while(start < end && !isalnum(s[start]))
                start ++;
            while(start < end && !isalnum(s[end]))
                end --;

            if(start > end || tolower(s[start]) != tolower(s[end]))
                return false;

            start ++;
            end --;
        }

        return true;
    }
};
// @lc code=end

