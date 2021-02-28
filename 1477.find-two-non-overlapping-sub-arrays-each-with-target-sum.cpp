/*
 * @lc app=leetcode id=1477 lang=cpp
 *
 * [1477] Find Two Non-overlapping Sub-arrays Each With Target Sum
 */

// @lc code=start
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int res = INT_MAX;
        int n = arr.size();
        int sum = 0;
        int s = 0;
        int minLen = INT_MAX;
        vector<int> minLens(n, INT_MAX);

        for(int e = 0; e < n; e ++) {
            sum += arr[e];
            while(sum > target) {
                sum -= arr[s];
                s ++;
            }
            if(sum == target) {
                int curLen = e - s + 1;
                if(s > 0 && minLens[s-1] != INT_MAX)
                    res = min(res, curLen + minLens[s-1]);
                minLen = min(minLen, curLen);
            }
            minLens[e] = minLen;
        }
        
        return res >= INT_MAX ? -1 : res;
    }
};
// @lc code=end

