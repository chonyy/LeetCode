/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copy;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;

        // If we haven't seen this node
        if(copy.find(node) == copy.end()) {
            // Create a new copy and map it
            copy[node] = new Node(node->val);
            // Rum DFS on the unseen neighbors
            for(auto no : node->neighbors) {
                copy[node]->neighbors.push_back(cloneGraph(no));
            }
        }


        return copy[node];
    }
};
// @lc code=end

