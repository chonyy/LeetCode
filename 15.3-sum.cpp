/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

// -4, -1, -1, 0, 1, 2

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i ++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int first = nums[i];
                int low = i + 1;
                int high = n - 1;
                while(low < high) {
                    int target = 0 - first;
                    int sum = nums[low] + nums[high];
                    if(sum == target) {
                        res.push_back(vector<int> {first, nums[low], nums[high]});
                        while(low < high && nums[low] == nums[low+1]) low ++;
                        while(low < high && nums[high] == nums[high-1]) high --;
                        low ++;
                        high --;
                    }
                    else if(sum < target) {
                        low ++;
                    }
                    else {
                        high --;
                    }
                }
            }
        }


        return res;
    }
};
// @lc code=end

