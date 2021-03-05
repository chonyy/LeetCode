/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(i = n-2; i >= 0; i --) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        if(i < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            int targetIdx = i;
            cout << "to swap " << targetIdx << endl;
            int changeIdx;
            int curMin = INT_MAX;
            for(int j = n-1; j > targetIdx; j --) {
                if(nums[j] > nums[targetIdx]) {
                    changeIdx = j;
                    break;
                }
            }
            cout << "Smallest " <<changeIdx << endl;
            swap(nums[changeIdx], nums[targetIdx]);
            reverse(nums.begin() + targetIdx + 1, nums.end());
        }
    }
};
// @lc code=end

