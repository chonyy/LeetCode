/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums, target);
        int high = higher_bound(nums, target);
        return {low, high};
    }

    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int res = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int num = nums[mid];
            if(num == target) {
                res = mid;
                high = mid -1;
            }
            else if(num > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }

    int higher_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int res = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int num = nums[mid];
            if(num == target) {
                res = mid;
                low = mid + 1;
            }
            else if(num > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }
};
// @lc code=end

