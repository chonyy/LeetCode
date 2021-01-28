/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    void backTrack(vector<vector<int>> &subs, vector<int> &sub, int i, vector<int> &nums) {
        subs.push_back(sub);

        for(int j = i; j < nums.size(); j ++) {
            sub.push_back(nums[j]);
            backTrack(subs, sub, j+1, nums);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        backTrack(subs, sub, 0, nums);
        return subs;
    }
};
// @lc code=end

