/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        // 0: Initial, 1: Visiting, 2: Visited
        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i ++) {
            if(visit(i, state, graph) == false)
                return false;
        }

        return true;
    }

    bool visit(int node, vector<int>& state, vector<vector<int>>& graph) {
        if(state[node] == 1)
            return false;
        if(state[node] == 2)
            return true;

        state[node] = 1;
        auto neighbors = graph[node];

        for(int neighbor : neighbors) {
            if(visit(neighbor, state, graph) == false)
                return false;
        }

        state[node] = 2;

        return true;
    }
};
// @lc code=end

