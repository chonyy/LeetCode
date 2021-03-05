/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
        stack<int> stk1;
        stack<int> stk2;

        ListNode* cur = l1;
        while(cur) { 
            stk1.push(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur) {
            stk2.push(cur->val);
            cur = cur->next;
        }

        int sum = 0;
        ListNode* list = new ListNode(0);
        while(!stk1.empty() || !stk2.empty()) {
            if(!stk1.empty()) {
                sum += stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()) {
                sum += stk2.top();
                stk2.pop();
            }

            list->val = sum % 10;
            cout << list->val << endl;
            ListNode* head = new ListNode(sum / 10);
            head->next = list;
            list = head;
            sum /= 10;
        }

        // return list;
        return list->val == 0 ? list->next : list;
    }
};
// @lc code=end

