/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates, target, 0, temp);
        return res;
    }

    void backtrack(vector<int>& candidates, int remain, int start, vector<int>& temp) {
        if(remain == 0) {
            res.push_back(temp);
            return;
        }

        if(remain < 0)
            return;

        for(int i = start; i < candidates.size(); i ++) {
            temp.push_back(candidates[i]);
            backtrack(candidates, remain-candidates[i], i, temp);
            temp.pop_back();
        }
    }
};
// @lc code=end

