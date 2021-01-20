/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;

        while(!(l1 == nullptr && l2 == nullptr && carry == 0)) {
            int val1 = l1 != nullptr ? l1-> val : 0;
            int val2 = l2 != nullptr ? l2-> val : 0;

            int sum = val1 + val2 + carry;

            ListNode* node = new ListNode(sum%10);
            carry = sum / 10;

            tail->next = node;
            tail = node;

            l1 = l1 != nullptr ? l1->next : l1;
            l2 = l2 != nullptr ? l2->next : l2;
        }
        return dummy->next;
    }
};
// @lc code=end
