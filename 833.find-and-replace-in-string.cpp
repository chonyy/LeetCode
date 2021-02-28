/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

// @lc code=start
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        int n = indexes.size();
        for(int i = 0; i < n; i ++) {
            sorted.push_back({indexes[i], i});
        }
        sort(sorted.begin(), sorted.end(), greater<>());

        for(auto p : sorted) {
            string original = sources[p.second];
            string target = targets[p.second];
            int idx = p.first;
            int l = original.size();
            string curStr = S.substr(idx, l);
            if(curStr == original) {
                S.replace(idx, l, target);
            }
        }

        return S;
    }
};
// @lc code=end

