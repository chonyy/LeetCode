/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX, two = INT_MAX;

        for(int num : nums) {
            if(num < one)
                one = num;
            else if(num > one && num < two)
                two = num;
            else if(num > two) 
                return true;
        }

        return false;
    }
};
// @lc code=end

