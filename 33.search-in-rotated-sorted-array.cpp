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
        if(!n) return -1;

        int low = 0, high = n -1;
        int first = nums[0];

        while(low <= high) {
            int mid = (low + high) / 2;
            int value = nums[mid];

            if(value == target){
                return mid;
            }

            bool amBig = value >= first;
            bool targetBig = target >= first;

            if(amBig == targetBig) {
                if(value < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else {
                if(value < target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

