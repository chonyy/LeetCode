/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int, int> m;

        for(int i = 0; i < n; i ++) {
            m[position[i]] = speed[i];
        }

        sort(position.begin(), position.end());
        double lastArrived = -1;
        int fleets = 0;

        for(int i = n-1; i >= 0; i --) {
            int distance = target - position[i];
            double time = (double)distance / m[position[i]];
            cout << time << endl;
            if(time > lastArrived) {
                fleets ++;
                lastArrived = time;
            }
        }

        return fleets;
    }
};
// @lc code=end

