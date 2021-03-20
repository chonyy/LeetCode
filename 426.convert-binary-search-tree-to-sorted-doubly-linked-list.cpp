/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* first;
    Node* prev;
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return nullptr;
        first = nullptr;
        prev = nullptr;
        inorder(root);
        first->left = prev;
        prev->right = first;
        return first;
    }

    void inorder(Node *root) {
        if(!root)
            return;

        inorder(root->left);

        if(first == nullptr) {
            first = root;
            prev = root;
        }
        else {
            prev->right = root;
            root->left = prev;
        }

        prev = root;
        inorder(root->right);
    }
};
// @lc code=end

