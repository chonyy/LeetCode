/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i ++) {
            if(nums[i] == target)
                return i;
        } 
        return -1;
    }
};
// @lc code=end

