/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>graph;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);

        for(auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> order;
        vector<int> courses(numCourses, 0);

        for(int i = 0; i < numCourses; i ++) {
            if(solve(courses, i, order)) return vector<int> {};
        }

        return order;
    }

    bool solve(vector<int> &courses, int idx, vector<int> &order) {
        if(courses[idx] == 1) return true;
        if(courses[idx] == 2) return false;

        courses[idx] = 1;

        for(int i : graph[idx]) {
            if(solve(courses, i, order)) return true;
        }

        courses[idx] = 2;
        order.insert(order.begin(), idx);
        return false;
    }
};
// @lc code=end

