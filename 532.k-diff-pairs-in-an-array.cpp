/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;

        for(int num : nums) {
            m[num] ++;
        }

        for(auto it = m.begin(); it !=  m.end(); it ++) {
            if(k == 0) {
                if(it->second > 1) {
                    res ++;
                }
            }
            else {
                int num = it->first + k;
                if(m.count(num)) {
                    res ++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

