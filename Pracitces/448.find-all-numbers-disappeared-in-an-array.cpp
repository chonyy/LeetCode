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
        for(int i = 0; i < n; i ++) {
            int num = abs(nums[i])-1;
            if(nums[num] > 0)
                nums[num] = -nums[num];
        }

        vector<int> res;
        int count = 0;
        for(int i = 0; i < n; i ++) {
            if(nums[i] > 0)
                res.push_back(i+1);
        }

        return res;
    }
};
// @lc code=end

