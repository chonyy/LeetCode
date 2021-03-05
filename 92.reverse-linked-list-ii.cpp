/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for(int i = 0; i < left - 1; i ++){
            prev = prev->next;
        }
        ListNode* tail = prev->next;
        ListNode* oldStart;

        for(int i = 0; i < right-left; i ++) {
            oldStart = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = oldStart;
        }

        return dummy->next;
    }
};
// @lc code=end

