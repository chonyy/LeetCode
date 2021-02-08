/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        cout << mid->val << endl;
        slow->next = nullptr;

        return merge(mergeSort(head), mergeSort(mid));
    }

    ListNode* merge(ListNode* l1, ListNode*l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next; 
            }
            else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }

        if(l1)
            dummy->next = l1;
        if(l2)
            dummy->next = l2;

        return head->next;
    }
};
// @lc code=end

