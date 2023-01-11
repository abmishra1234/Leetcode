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

//#define FORREF
#ifndef FORREF
/*
    I can solve this problem using the recursive and iterative approach

    Approach 01: Recursive
    Time Complexity:
    Space Complexity:

    Approach 02 : Iterative
    Time Complexity:
    Space Complexity:

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:

    void util(ListNode* head, deque<ListNode*> &s, int &carry, ListNode* &newhead) {
        if (!head) return;
        util(head->next, s, carry, newhead);

        // While stack unwinding you have to sum the add and update
        int val = head->val + carry;

        if (!s.empty()) {
            ListNode* n1 = s.front(); s.pop_front();
            val += n1->val;
        }
        carry = val / 10;
        val = val % 10;

        if (newhead == nullptr) {

            newhead = head;
            newhead->next = nullptr;
        }
        else
        {
            head->next = newhead;
            newhead = head;
        }
        newhead->val = val;
     }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // iterate and push all the node into the s
        deque<ListNode*> s;
        while (l1) {
            s.push_front(l1);
            l1 = l1->next;
        }

        int carry = 0;
        ListNode* newhead = nullptr;
        util(l2, s, carry, newhead);

        while (!s.empty()) {
            ListNode* n1 = s.front(); s.pop_front();
            n1->val += carry;
            carry = n1->val / 10;
            n1->val = n1->val % 10;

            n1->next = newhead;
            newhead = n1;
        }

        if (carry > 0) {
            ListNode* n1 = new ListNode(carry);
            n1->next = newhead;
            newhead = n1;
        }
        
        return newhead;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF