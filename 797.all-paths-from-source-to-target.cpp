/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        backtrack(res, graph, 0, path);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<vector<int>>& graph, int cur, vector<int>& path) {
        if(cur == graph.size() - 1) {
            res.push_back(path);
            return;
        }

        for(int neighbor : graph[cur]) {
            path.push_back(neighbor);
            backtrack(res, graph, neighbor, path);
            path.pop_back();
        }
    }
};
// @lc code=end

