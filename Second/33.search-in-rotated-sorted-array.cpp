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
        int start = 0;
        int end = n-1;
        int first = nums[0];
        while(start <= end) {
            int mid = start + (end - start) / 2;
            cout << mid << endl;
            int num = nums[mid];
            if(num == target)
                return mid;
            bool amBig = num >= first;
            bool targetBig = target >= first;
            if(amBig == targetBig) {
                if(num > target) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                if(num > target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

