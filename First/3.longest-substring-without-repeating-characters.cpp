/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> appeared;
        int maxLen = 0;
        int i = 0;
        int j = 0;

        while(j < s.length()) {
            if(appeared.find(s[j]) == appeared.end()) {
                appeared.insert(s[j]);
                j ++;
                maxLen = max(maxLen, j-i);
            }
            else {
                appeared.erase(s[i]);
                i ++;
            }
        }
        return maxLen;
    }
};
// @lc code=end

