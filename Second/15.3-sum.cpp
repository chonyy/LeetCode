/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i ++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            cout << -target << endl;
            int left = i + 1;
            int right = n-1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum < target) {
                    left ++;
                }
                else if(sum > target) {
                    right --;
                }
                else {
                    res.push_back({-target, nums[left], nums[right]});
                    while(left < right && nums[right-1] == nums[right])
                        right --;
                    while(left < right && nums[left+1] == nums[left])
                        left ++;
                    right --;
                    left ++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

