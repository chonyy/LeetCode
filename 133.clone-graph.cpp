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
    unordered_set<Node*> walked;
    Node* cloneGraph(Node* node) {
        Node* newNode = new Node(node->val);
        walked.insert(node);

        cout << newNode->val << endl;
        for(auto no : node->neighbors) {
            // if not walked
            if(walked.find(node) != walked.end()) {
                newNode->neighbors.push_back(cloneGraph(no));

            }
        }

        return newNode;
    }
};
// @lc code=end

