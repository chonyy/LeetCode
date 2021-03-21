/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> bucket(n, 0);

        for(int num : nums)
            bucket[num] += num;

        int take = 0, skip = 0;
        for(int i = 0; i < n; i ++) {
            int takei = skip + bucket[i];
            int skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }

        return max(take, skip);
    }
};
// @lc code=end

