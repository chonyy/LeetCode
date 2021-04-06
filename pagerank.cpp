# include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        vector<Node*> parents;
        vector<Node*> children;
        double p = 0.0;
};

void PageRank_One_Iteration(vector<Node*>& graph) {
    // Loop through evey node in the graph
    for(auto node : graph) {
        double parentPSum = 0.0;
        auto &parents = node->parents;

        // Skip if it's the root
        if(parents.size() == 0)
            continue;

        // Sum up the parent's proportional P
        for(auto parent : parents) {
            parentPSum += parent->p / parent->children.size();
        }
        node->p = parentPSum;
    }
}

void solve(vector<vector<int>>& edges, int n) {
    vector<Node*> graph(n);
    int iterations = 10;

    for(int i = 0; i < n; i ++) {
        graph[i] = new Node();
    }

    // Constructing the graph
    for(auto e : edges) {
        graph[e[0]]->children.push_back(graph[e[1]]);
        graph[e[1]]->parents.push_back(graph[e[0]]);
    }

    // Init the root with 1.0 possibility
    graph[0]->p = 1.0;

    // Run PageRank for each iteration
    for(int i = 0; i < iterations; i ++) {
        PageRank_One_Iteration(graph);
    }

    for(auto node : graph) {
        cout << node->p << endl;
    }
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 6}, {3, 2}, {3, 4}, {3, 5}, {4, 5}, {4, 7}, {4, 8}, {5, 6}, {5, 7}, {6, 7}, {6, 8}, {7, 8}};

    solve(edges, 9);

    return 0; 
}