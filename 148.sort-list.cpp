class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        int len = 1;
        ListNode* cur = head;
        while(cur){
            len ++;
            cur = cur->next;  
        } 

        ListNode dummy(0);
        dummy.next = head;
        ListNode *l;
        ListNode *r;
        ListNode *tail;

        for(int n = 1; n < len; n <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            while(cur) {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }

        return dummy.next;
    }


private:
    // Split the list into two parts, first n elements and thr rest.
    // Return the head of the rest.
    ListNode* split(ListNode* head, int n) {
        while(--n && head) {
            head = head->next;
        }

        ListNode* rest = head ? head->next : nullptr;
        if(head)
            head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode *l1, ListNode *l2) {
        ListNode *tail = new ListNode(0);
        ListNode *head = tail;

        while(l1 && l2) {
            if(l1->val > l2->val) {
                tail->next = l2;
                l2 = l2->next;
            }
            else {
                tail->next = l1;
                l1 = l1->next;
            }
            tail = tail->next;
        }


        if(l1)
            tail->next = l1;
        if(l2)
            tail->next = l2;

        while(tail->next)
            tail = tail->next;

        return {head->next, tail};
    }
};


// Space O(lgN)
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(!head || !head->next) return head;

//         ListNode *slow = head;
//         ListNode *fast = head->next;

//         while(fast && fast->next) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         ListNode *mid = slow->next;
//         slow->next = nullptr;

//         return(merge(sortList(head), sortList(mid)));
//     }

//     ListNode* merge(ListNode *l1, ListNode *l2) {
//         ListNode *tail = new ListNode(0);
//         ListNode *head = tail;

//         while(l1 && l2) {
//             if(l1->val > l2->val) {
//                 tail->next = l2;
//                 l2 = l2->next;
//             }
//             else {
//                 tail->next = l1;
//                 l1 = l1->next;
//             }
//             tail = tail->next;
//         }

//         if(l1)
//             tail->next = l1;
//         if(l2)
//             tail->next = l2;

//         return head->next;
//     }
// };
// @lc code=end

