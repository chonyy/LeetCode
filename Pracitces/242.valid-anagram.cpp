/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        for(char c : s)
            m[c] ++;

        for(char c : t)
            m[c] --;

        for(auto it : m)
            if(it.second != 0)
                return false;

        return true;
    }
};
// @lc code=end

