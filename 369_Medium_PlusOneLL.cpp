using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

#define FORREF
#ifndef FORREF
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

/*
    Your task is to write both recursive and iterative code for this problem??
    
    1. Recursive Approach - 
    Time Complexity - 
    Space Complexity - 

    2. Iterative Approach -
    Time Complexity -
    Space Complexity -

*/
class Solution {
public:
    void util(ListNode* head, bool& fadd, int& carry) {
        if (!head) return;
        util(head->next, fadd, carry);

        // stack unwinding step
        int val = 0;
        if (fadd) {
            fadd = false;
            val = head->val + 1;
            carry = val / 10;
            val = val % 10;
            head->val = val;
        }
        else
        {
            val = head->val + carry;
            carry = val / 10;
            val = val % 10;
            head->val = val;
        }
    }

    ListNode* rplusOne(ListNode* head) {
        bool fadd = true; // one's you add, make it false
        int carry = 0; // default value will be 0

        util(head, fadd, carry);

        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }

    ListNode* plusOne(ListNode* head) {
        bool fadd = true; // one's you add, make it false
        int carry = 0; // default value will be 0

        //util(head, fadd, carry);
        stack<ListNode*> s;
        
        ListNode* h = head;
        while (h) {
            s.push(h);
            h = h->next;
        }

        ListNode* newhead = nullptr;
        int val = 0;
        while (false == s.empty()) {
            ListNode* temp = s.top(); s.pop();
            if (fadd) {
                fadd = false;
                val = temp->val + 1;
                carry = val / 10;
                val = val % 10;
                temp->val = val;
                temp->next = nullptr;
                newhead = temp;
            }
            else {
                val = temp->val + carry;
                carry = val / 10;
                val = val % 10;
                temp->val = val;

                temp->next = newhead;
                newhead = temp;
            }
        }

        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            node->next = newhead;
            newhead = node;
        }
        return newhead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF