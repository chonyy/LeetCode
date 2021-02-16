/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> res;
        vector<int> states(numCourses, 0);

        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < numCourses; i ++) {
            if(find(i, graph, states, res) == false)
                return {};
        }

        reverse(res.begin(), res.end());

        return res;
    }

    bool find(int node, vector<vector<int>>& graph, vector<int>& states, vector<int>& res) {
        if(states[node] == 1)
            return false;

        if(states[node] == 2)
            return true;

        states[node] = 1;

        auto neighbors = graph[node];
        for(int neighbor : neighbors) {
            if(!find(neighbor, graph, states, res))
                return false;
        }

        states[node] = 2;
        res.push_back(node);
        return true;
    }
};
// @lc code=end

