/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if(!head)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // getting mid node
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // reverse the list
        ListNode* reversed = reverse(mid);

        merge(head, reversed);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *next = nullptr;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    void merge(ListNode* head1, ListNode* head2) {
        while(head2) {
            ListNode* next = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = next;
        }
    }
};
// @lc code=end

