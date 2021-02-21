/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0;
        int high = n - 1;
        vector<int> res;

        while(low <= high) {
            int sum = numbers[low] + numbers[high];
            if(sum > target)
                high --;
            else if(sum < target)
                low ++;
            else {
                return {low+1, high+1};
            }
        }
        return {low, high};
    }
};
// @lc code=end

