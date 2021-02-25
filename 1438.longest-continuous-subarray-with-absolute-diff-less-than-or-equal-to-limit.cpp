/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQ;
        deque<int> minQ;

        int ans = 0;
        int l = 0;

        for(int r = 0; r < nums.size(); r ++) {
            while(!minQ.empty() && nums[r] < minQ.back())
                minQ.pop_back();
            while(!maxQ.empty() && nums[r] > maxQ.back())
                maxQ.pop_back();

            minQ.push_back(nums[r]);
            maxQ.push_back(nums[r]);

            while(maxQ.front() - minQ.front() > limit) {
                if(maxQ.front() == nums[l])
                    maxQ.pop_front();
                if(minQ.front() == nums[l])
                    minQ.pop_front();

                l ++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
// @lc code=end

