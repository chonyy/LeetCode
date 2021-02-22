/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int start = 0;
        int end = 0;
        int curMin = INT_MAX;
        int size = n - k;
        int curPoints = 0;
        int sum = 0;

        while(end < n) {
            sum += cardPoints[end];
            curPoints += cardPoints[end];
            if(end - start + 1 > size) {
                curPoints -= cardPoints[start];
                start ++;
            }
            if(end - start + 1 == size) {
                curMin = min(curMin, curPoints);
            }
            end ++;
        }
        return sum - curMin;
    }
};
// @lc code=end

