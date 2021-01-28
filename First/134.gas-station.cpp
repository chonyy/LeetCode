/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1;
        int end = 0;
        int sum = gas[start] - cost[start];

        while(start > end) {
            if(sum >= 0) {
                sum += gas[end] - cost[end];
                end ++;
            }
            else {
                start --;
                sum += gas[start] - cost[start];
            } 
        }

        return sum >= 0 ? start : -1;
    }
};
// @lc code=end

