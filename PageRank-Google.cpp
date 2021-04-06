# include<bits/stdc++.h>

using namespace std;

// The image for this example (with answer)
// https://math.stackexchange.com/questions/3036994/what-is-the-probability-of-passing-through-a-node-in-a-directed-graph

class Node {
    public:
        vector<Node*> parents;
        vector<Node*> children;
        double p = 0.0;
};

unordered_map<Node*, double> cache;

double getP(Node* node, vector<Node*>& graph) {
    // Return when we reach the root
    if(node->parents.size() == 0)
        return node->p;

    // Return if we calculated it before
    if(cache.count(node) != 0)
        return cache[node];

    auto &parents = node->parents;
    double newP = 0.0;

    // new P = sum of all the parent's P divided by the parent's number of children
    for(auto parent : parents) {
        newP += getP(parent, graph) / parent->children.size();
    }

    cache[node] = newP;
    node->p = newP;
    return newP;
}

void solve(vector<vector<int>>& edges, int n) {
    vector<Node*> graph(n);
    vector<Node*> dest;

    for(int i = 0; i < n; i ++) {
        graph[i] = new Node();
    }

    // Constructing the directed graph
    for(auto e : edges) {
        graph[e[0]]->children.push_back(graph[e[1]]);
        graph[e[1]]->parents.push_back(graph[e[0]]);
    }

    // Getting the destinations, the node that has no child, this is where the grasshopper will be trapped
    for(auto node : graph) {
        if(node->children.size() == 0)
            dest.push_back(node);
    }

    // Init the root with 1.0 possibility
    graph[0]->p = 1.0;

    // Starting to get P from every destination
    for(auto node : dest) {
        node->p = getP(node, graph);
    }

    for(auto node : graph) {
        cout << node->p << endl;
    }
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 6}, {3, 2}, {3, 4}, {3, 5}, {4, 5}, {4, 7}, {4, 8}, {5, 6}, {5, 7}, {6, 7}, {6, 8}, {7, 8}};

    solve(edges, 10);

    return 0; 
}