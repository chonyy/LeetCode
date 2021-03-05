/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
public:
    int count = 0;
    int len;
    int countArrangement(int n) {
        len = n;
        if(n == 0)
            return 0;
        vector<int> nums(n+1);
        for(int i = 0; i <= len; i ++)
            nums[i] = i;

        backtracking(n, nums);
        return count;
    }

    void backtracking(int start, vector<int>& nums) {
        if(start == 0) {
            cout << endl;
            count ++;
            return;
        }

        for(int i = start; i > 0; i --) {
            swap(nums[start], nums[i]);
            if(nums[start] % start == 0 || start % nums[start] == 0)  {
                cout << nums[start] << " ";
                backtracking(start-1, nums);
            }
            swap(nums[i], nums[start]);
        }
    }
};
// @lc code=end

