/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        int start = -1;
        int end = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                int low = mid;
                while(low >= 0 && nums[low] == target) {
                    start = low;
                    low --;
                }
                int high = mid;
                while(high < n && nums[high] == target) {
                    end = high;
                    high ++;
                }
                break;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid -1;
            }
        }

        return {start, end};
    }
};
// @lc code=end

