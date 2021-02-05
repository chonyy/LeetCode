/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;

        for(int i = 0; i < n; i ++) {
            if(i > reach) 
                return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

