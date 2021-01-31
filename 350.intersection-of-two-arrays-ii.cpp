/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;

        for(int num : nums1)
            map[num] ++;

        for(int num : nums2) {
            if(map[num]) {
                res.push_back(num);
                map[num] --;                
            }
        }

        return res;
    }
};
// @lc code=end

