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
        Node *cur = head;

        if(!head) return head;

        // First pass, create clone 
        while(cur) {
            Node *newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }


        cur = head;
        // Second pass, link the random
        while(cur) {
            Node *cloneNode = cur->next;
            if(cur->random)
                cloneNode->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        Node *headCP = head->next;
        // Third pass, fix the next pointers
        while(cur) {
            Node *cloneNode = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            if(cur)
                cloneNode->next = cur->next;

            // Node *cloneNode = cur->next;
            // cur->next = cur->next->next;
            // cur = cur->next;
            // if(cur)
            //     cloneNode->next = cur->next;    
        }

        cur = headCP;
        while(cur) {
            cout << cur->val << endl;
            cur = cur->next;
        }


        return headCP;
    }

    // Linear space solution
    // Node* copyRandomList(Node* head) {
    //     unordered_map<Node*, Node*> m;
    //     Node *cur = head;

    //     while(cur) {
    //         Node *newNode = new Node(cur->val);
    //         m[cur] = newNode;
    //         cur = cur->next;
    //     }

    //     cur = head;

    //     while(cur) {
    //         Node *cloneNode = m[cur];
    //         cloneNode->next = m[cur->next];
    //         cloneNode->random = m[cur->random];
    //         cout << cloneNode->val << endl;
    //         cur = cur->next; 
    //     }

    //     return m[head];
    // }
};
// @lc code=end

