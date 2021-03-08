/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(nullptr, root);

        vector<int> res;
        queue<TreeNode*> q;
        set<TreeNode*> visited;
        q.push(target);

        while(K --) {
            int curSize = q.size();
            for(int i = 0; i < curSize; i ++) {
                TreeNode* curNode = q.front();
                q.pop();
                for(auto node : graph[curNode]) {
                    if(visited.count(node) == 0)
                        q.push(node);
                    visited.insert(curNode);
                }
            }
        }

        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }

    void buildGraph(TreeNode* parent, TreeNode* child) {
        if(parent) {
            graph[parent].push_back(child);
            graph[child].push_back(parent);
        }

        if(child->left)
            buildGraph(child, child->left);
        if(child->right)
            buildGraph(child, child->right);
    }
};
// @lc code=end

