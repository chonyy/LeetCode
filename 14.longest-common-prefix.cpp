/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(!strs.size()) return "";

        string res = "";
        int idx = 0;
        int n = strs[0].size();
        int m = strs.size();
        while(idx < n) {
            char c = strs[0][idx];
            for(int j = 1; j < m; j ++) {
                if(idx > strs[j].size() - 1)
                    return res;
                if(strs[j][idx] != c)
                    return res;
            }
            res += c;
            idx ++;
        }
        return res;
    }
};
// @lc code=end

