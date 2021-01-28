/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int num : nums) {
            m[num] ++;
        }

        for(auto it : m) {
            if(it.second > 1)
                return true;
        }

        return false;
    }
};
// @lc code=end

