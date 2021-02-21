/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num : nums) {
            if(m[num])
                return num;
            m[num] ++;
        }
        return 0;
    }
};
// @lc code=end

