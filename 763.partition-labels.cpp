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
        int n = S.size();
        for(int i = 0; i < n; i ++) {
            last[S[i]] = i;
        }

        int curLast = 0;

        for(int i = 0; i < n ; i ++) {
            curLast = last[S[i]];
        }
    }
};
// @lc code=end

