/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int end = n-1;
        int start = 0;

        while(start < end) {
            swap(s[start], s[end]);
            start ++;
            end --;
        }
    }
};
// @lc code=end

