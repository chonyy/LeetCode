/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = nums[0];

        for(int num : nums) {
            if(majority == num)
                count ++;
            else {
                count --;
            }

            if(count == 0) {
                majority = num;
                count ++;
            }
        }
        return majority;
    }
};
// @lc code=end

