/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    static bool compare(const string s1, const string s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int res = 0;
        sort(words.begin(), words.end(), compare);

        for(string word : words) {
            for(int i = 0; i < word.size(); i ++) {
                string subWord = word.substr(0, i) + word.substr(i+1);
                dp[word] = max(dp[word], dp[word.substr(0, i) + word.substr(i+1)]+1);
            }
            res = max(res, dp[word]);
        }


        return res;
    }
};
// @lc code=end

