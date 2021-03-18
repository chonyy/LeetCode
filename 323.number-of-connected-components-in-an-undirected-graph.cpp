/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start
class Solution {
public:
    vector<int> parents;
    int countComponents(int n, vector<vector<int>>& edges) {
        parents = vector<int>(n, 0);
    
        // Init: parent is the node itself
        for(int i = 0; i < n; i ++) {
            parents[i] = i;
        }

        // Union the nodes
        for(auto edge : edges) {
            Union(edge[0], edge[1]);
        }

        unordered_set<int> set;
        for(int i = 0; i < n; i ++) {
            set.insert(find(i));
        }

        return set.size();
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        parents[pu] = pv; 
    }

    int find(int u) {
        if(parents[u] != u)
            u = find(parents[u]);
        return parents[u];
    }
};
// @lc code=end

