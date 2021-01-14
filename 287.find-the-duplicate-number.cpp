/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 1;
        int mid;
        while(low < high) {
            mid = (low + high) / 2;
            int count = 0;
            for(int i : nums)
                if(i <= mid)
                    count ++;

            if(count <= mid) {
                low = mid + 1;
            }
            else 
                high = mid;
            cout << mid << endl;
        }
        return low;
    }
};
// @lc code=end

