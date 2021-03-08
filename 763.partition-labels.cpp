/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> last;
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int n = S.size();
        for(int i = 0; i < n; i ++) {
            last[S[i]] = i;
        }

        int curLast = 0;
        int anchor = 0;

        for(int i = 0; i < n ; i ++) {
            curLast = max(curLast, last[S[i]]);
            if(i == curLast) {
                res.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }

        return res;
    }
};
// @lc code=end

