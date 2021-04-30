// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            next = nullptr;
        }
};

class Stack {
    public:
        Node* top = nullptr;
        void push(int val) {
            if(top == nullptr) {
                top = new Node(val);
                return;
            }
            // Link it to the previous
            Node* node = new Node(val);
            node->next = top;
            top = node;
        }

        int pop() {
            if(top == nullptr) {
                return -1;
            }

            Node* oldTop = top;
            top = top->next;
            int topVal = oldTop->val;
            delete(oldTop);
            return topVal;
        }

        void print() {
            Node* cur = top;
            while(cur) {
                cout << cur->val << " ";
                cur = cur->next;
            }
            cout << endl;
        }
};

int main() {
    Stack stk = Stack();
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.push(6);
    stk.print();

    return 0;
}