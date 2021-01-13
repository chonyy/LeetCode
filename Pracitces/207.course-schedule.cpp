/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);

        for(auto &p : prerequisites)
            graph[p[1]].push_back(p[0]);

        // init 0: UNK, 1: Visiting, 2: Visisted
        vector<int> course(numCourses, 0);

        for(int i = 0; i < numCourses; i ++) {
            if(dfs(i, course)) return false;
        }

        return true;
    }

    bool dfs(int cur, vector<int> &course) {
        if(course[cur] == 1) return true;
        if(course[cur] == 2) return false;

        course[cur] = 1;

        for(int i : graph[cur]) {
            if(dfs(i, course)) return true;
        }

        course[cur] = 2;
        return false;
    }
};
// @lc code=end

