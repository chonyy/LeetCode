/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();

        for(int i = 0; i < n; i ++) {
            int targetIdx = abs(nums[i]) - 1;
            if(nums[targetIdx] < 0) {
                res.push_back(targetIdx+1);
                continue;
            }
            nums[targetIdx] *= -1;
        }

        return res;
    }
};
// @lc code=end

