/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1, -1};

        int low = lowerBound(nums, target);
        int high = higherBound(nums, target);

        return {low, high};
    }

    int lowerBound(vector<int> &nums, int target) {
        int res = -1;
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int mid;

        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                res = mid;
                high = mid - 1;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else    
                low = mid + 1;
        }
        return res;
    }

    int higherBound(vector<int> &nums, int target) {
        int res = -1;
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int mid;

        while(low <= high) {
            mid = (low + high) / 2;
            cout << mid << endl;
            if(nums[mid] == target) {
                res = mid;
                low = mid + 1;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else    
                low = mid + 1;
        }
        return res;
    }
};
// @lc code=end

