using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

//#define FORREF
#ifndef FORREF
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:

    ListNode* solve(ListNode* l1, ListNode* l2, ListNode* head, ListNode* tail, int carry) {
        if (!l1 && !l2) {
            if (carry) {
                ListNode* temp = new ListNode(carry);
                if (!head) tail = head = temp;
                else {
                    tail->next = temp;
                    tail = temp;
                }
            }
            return head;
        }
        else
        {
            ListNode* temp = new ListNode(0);
            if (!l1) {
                temp->val = carry + l2->val;
                carry = 0;
            }
            else if (!l2) {
                temp->val = carry + l1->val;
                carry = 0;
            }
            else {
                temp->val = carry + l1->val + l2->val;
                carry = 0;
                if (temp->val >= 10) {
                    carry = temp->val / 10;
                    temp->val %= 10;
                }
            }

            if (!head) tail = head = temp;
            else {
                tail->next = temp;
                tail = temp;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            solve(l1, l2, head, tail, carry);
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        return solve(l1, l2, head, tail, 0);
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF