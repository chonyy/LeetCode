/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

// @lc code=start
class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2) {
        int xDiff = p1[0] - p2[0];
        int yDiff = p1[1] - p2[1];

        return xDiff * xDiff + yDiff * yDiff;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> distances;

        distances.insert(distance(p1, p2));
        distances.insert(distance(p1, p3));
        distances.insert(distance(p1, p4));
        distances.insert(distance(p2, p3));
        distances.insert(distance(p2, p4));
        distances.insert(distance(p3, p4));

        return distances.count(0) ? false : distances.size() == 2;
    }
};
// @lc code=end

