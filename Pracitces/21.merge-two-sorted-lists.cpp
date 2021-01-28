/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }

        while(l1) {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2) {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

