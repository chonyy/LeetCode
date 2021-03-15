/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the array
        sort(nums.begin(), nums.end());

        int res = 0;
        int curClosest = INT_MAX;
        int n = nums.size();
        // Pick the first element
        for(int i = 0; i < n-2; i ++) {
            int left = i + 1;
            int right = n - 1;
            // two pointer
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target) 
                    left ++;
                else
                    right --;
                
                // compare the distance
                int distance = abs(target - sum);
                if(distance < curClosest) {
                    res = sum;
                    curClosest = distance;
                }
            }
        }

        return res;
    }
};
// @lc code=end

