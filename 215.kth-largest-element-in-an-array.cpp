/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }

    int quickSelect(vector<int> &nums, int low, int high, int k) {
        int pivot = low;

        for(int i = low; i < high; i ++) {
            if(nums[i] <= nums[high])
                swap(nums[pivot++], nums[i]);
        }
        swap(nums[pivot], nums[high]);

        int count = high - pivot + 1;

        if(count == k)
            return nums[pivot];
        else if(count < k)
            return quickSelect(nums, 0, pivot-1, k-count);
        return quickSelect(nums, pivot+1, high, k);
    }
};
// @lc code=end

