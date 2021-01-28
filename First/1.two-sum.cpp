/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        map<int, int> m;

        for(int i = 0; i < n; i ++) {
            int toFind = target - nums[i];
            if(m.find(toFind) != m.end()) {
                res.push_back(i);
                res.push_back(m[toFind]);
                break;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return res;
    }
};
// @lc code=end

