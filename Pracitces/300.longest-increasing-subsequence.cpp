/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> tails(n);

        int size = 0;

        for(int num : nums) {
            int i = 0, j = size;
            while(i != j) {
                int m = (i + j) / 2;
                if(tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if(i == size) size ++;
        }
        return size;
    }
};
// @lc code=end

