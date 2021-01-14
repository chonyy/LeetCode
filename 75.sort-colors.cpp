/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n -1;
        int idx = 0;

        while(idx <= end && start < end) {
            if(nums[idx] == 0) {
                swap(nums[start++], nums[idx++]);
            }
            else if(nums[idx] == 2) {
                swap(nums[end], nums[idx]);
                end --;
            }
            else
                idx ++;

        }
    }
};
// @lc code=end

