/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution {
public:
    vector<int> dir = {0, 1};
    bool isRobotBounded(string instructions) {
        vector<int> cur = {0, 0};
        for(char inst : instructions) {
            if(inst == 'G') {
                cur[0] += dir[0];
                cur[1] += dir[1];
            }
            else if(inst == 'L') {
                dir = {-dir[1], dir[0]};
            }
            else {
                dir = {dir[1], -dir[0]};
            }
        }

        cout << cur[0] << " " << cur[1] << endl;
        return cur[0] == 0 && cur[1] == 0 || !(dir[0] == 0 && dir[1] == 1);
    }
};
// @lc code=end

0, 1
-1, 0
1, 0