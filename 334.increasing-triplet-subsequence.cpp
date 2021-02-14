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
            if(num < one) {
                one = num;
            }
            if(num > one && num < two) {
                two = num;
            }
            if(num > two)
                return true;

            cout << one << " " << two << endl;
        }
        return false;
    }
};
// @lc code=end

