/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size()-1;
        int left = 0;
        int right = n;
        int curMax = 0;
        while(left <= right) {
            int vertical = min(height[left], height[right]);
            int width = right - left;
            int volume = vertical * width;

            curMax = max(curMax, volume);
        
            if(height[left] < height[right])
                left ++;
            else
                right --;
        }
        return curMax;
    }
};
// @lc code=end

