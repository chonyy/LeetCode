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
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict);
    }

    bool solve(string &s, unordered_set<string> dict) {
        int n = s.size();

        if(m.count(s)) return m[s];
        if(dict.count(s)) {
            m[s] = true;
            return true;
        }
        
        for(int i = 1; i < n; i ++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if(solve(left, dict) && dict.count(right)) {
                m[s] = true;
                return true;
            }
        }
        m[s] = false;
        return false;
    }
};
// @lc code=end

