/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;

        Node* head = root;
        while(head) {
            Node* dummy = new Node(0);
            Node* temp  = dummy;
            // head is at the top level
            // temp traversing the level below, level order
            while(head) {
                if(head->left) {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right) {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }

        return root;
    }
};
// @lc code=end

