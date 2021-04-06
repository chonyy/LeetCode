/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
	for(int i =0; i < n-1; i ++) {
		if(nums[i+1] < nums[i]) {
			return nums[i+1];
}
}
return nums[0];

    }
};
// @lc code=end

