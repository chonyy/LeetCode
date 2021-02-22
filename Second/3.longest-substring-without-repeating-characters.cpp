/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int maxLen = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            if(set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                j++;
                maxLen = max(maxLen, j-i);
            }
            else {
                cout << "erase " << s[i] << endl; 
                set.erase(s[i]);
                i ++;
            }
        }

        return maxLen;
    }
};
// @lc code=end

