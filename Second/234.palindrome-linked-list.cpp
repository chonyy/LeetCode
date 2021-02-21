/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {

        if(!head) return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Starting from the middle
        ListNode *mid = slow->next;
        slow->next = nullptr;

        ListNode* reversedHead = reverse(mid);

        while(head && reversedHead) {
            if(head->val != reversedHead->val)
                return false;

            head = head->next;
            reversedHead = reversedHead->next;
        }
        return true;
    }

    ListNode* reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *next = nullptr;

        while(head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }
};
// @lc code=end

