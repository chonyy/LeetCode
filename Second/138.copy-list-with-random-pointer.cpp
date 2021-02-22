/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur;
        cur = head;
        Node *dummy = new Node(0);
        Node* newHead = dummy;

        unordered_map<Node*, Node*> m;

        while(cur) {
            Node* newNode = new Node(cur->val);
            newHead->next = newNode;
            newHead = newHead->next;

            m[cur] = newHead;

            cur = cur->next;
        }

        cur = head;
        newHead = dummy->next;

        while(cur) {
            Node* randomNode = m[cur->random];
            newHead->random = randomNode;
            newHead = newHead->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

