class Solution {
public:
    unordered_set<int> visited;
    bool hasCycle(int node, vector<vector<int>>& graph, vector<int>& state, int parent) {
        if(state[node] == 2) {
            return false;
        }
        if(state[node] == 1) {
            return true;
        }
        
        cout << "walk " << node << endl;
        state[node] = 1;
        visited.insert(node);
        auto& neighbors = graph[node];
        for(auto nei : neighbors) {
            if(nei == parent)
                continue;
            if(hasCycle(nei, graph, state, node))
                return true;
        }
        
        state[node] = 2;
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        // Construct graph
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> state(n, 0);
        
        if(hasCycle(0, graph, state, -1))
            return false;
        
        for(int i = 0; i < n; i ++)
            if(visited.count(i) == 0)
                return false;
        
        return true;
    }
};