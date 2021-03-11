/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // 1. push the asteroids to stack one by one
        // 2. if the rock is going right, push it directly into stack
        // 3. if the rock is going left, collide with the rocks in stack
        stack<int> rocks;

        for(int rock : asteroids) {
            cout << rock << endl;
            if(rock < 0) {
                while(!rocks.empty() && rocks.top() > 0 && abs(rock) > abs(rocks.top())) {
                    rocks.pop();
                }
                if(rocks.empty() || rocks.top() < 0)
                    rocks.push(rock);
                else if(!rocks.empty() && abs(rock) == abs(rocks.top()))
                    rocks.pop();
            }
            else {
                rocks.push(rock);
            }
        }

        vector<int> res;
        while(!rocks.empty()) {
            res.push_back(rocks.top());
            rocks.pop();
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};
// @lc code=end

