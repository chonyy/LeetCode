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
        if(!head || !head->next)
            return head;
        
        ListNode* cur = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int len = 0;
        while(cur) {
            cur = cur->next;
            len ++;
        }

        ListNode* left;
        ListNode* right;
        ListNode* tail;
        for(int i = 1; i < len; i <<= 1) {
            cur = dummy->next;
            tail = dummy;
            while(cur) {
                left = cur;
                cout << left->val << endl;
                right = split(cur, i);
                cur = split(right, i);
                auto merged = merge(left, right);
                tail->next = merged.first;
                tail = merged.second;
            }
        }

        return dummy->next;
    }

    ListNode* split(ListNode* head, int n) {
        while(head && --n) {
            head = head->next;
        }
        ListNode* rest = head ? head->next : nullptr;
        if(head)
            head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        // cout << "merge" << l1->val << l2->val << endl;

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

        dummy->next = l1 ? l1 : l2;
        while(dummy->next)
            dummy = dummy->next;

        cout << "head " << head->next->val << endl;
        cout << "tail " << dummy->val << endl; 
        return {head->next, dummy};
    }
};
// @lc code=end

