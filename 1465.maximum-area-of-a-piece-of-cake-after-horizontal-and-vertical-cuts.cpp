/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
class Solution {
public:
    int getMax(vector<int>& arr, int maxx) {
        sort(arr.begin(), arr.end());
        int curMax = max(arr[0], maxx - arr.back());
        for(int i = 1; i < arr.size(); i ++) {
            curMax = max(curMax, arr[i] - arr[i-1]);
        }
        return curMax;
    }

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxH = getMax(horizontalCuts, h);
        int maxW = getMax(verticalCuts, w);

        return (long)maxH * maxW % (1000000000 + 7);
    }
};
// @lc code=end

