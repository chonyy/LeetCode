/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i ++) {
            int num = nums[i] < 0 ? -nums[i] : nums[i];
            num --; 
            if(nums[num] > 0)
                nums[num] *= -1;
        }

        for(int i = 0; i < n; i ++) {
            if(nums[i] > 0)
                res.push_back(i+1);
        }

        return res;
    }
};
// @lc code=end

