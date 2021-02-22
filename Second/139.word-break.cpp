/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return solve(s, set);
    }

    bool solve(string s, unordered_set<string> set) {
        // In memory
        if(m.count(s))
            return m[s];

        // Answer solved
        if(set.count(s)) {
            m[s] = true;
            return true;
        }

        for(int i = 0; i < s.size(); i ++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if(set.count(right) && solve(left, set)) {
                m[left] = true;
                return true;
            }
        }
        m[s] = false;
        return false;
    }
};
// @lc code=end

