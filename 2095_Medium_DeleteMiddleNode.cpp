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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

/*
    There are two different approach possible here
    1. Recursive Approach
    Summary:
    Time Complexity: O(n)
    Space Complexity : O(n)

    2. Iterative Approach
    How you will improve recursive solution using the iterative solution?
    
*/

class Solution {
public:
    // For handling the recursive call
    void util(ListNode* head, int &l, int &r, ListNode* &newhead) {
        if (!head) {
            if (l % 2 == 0) l = (l - 1) / 2;
            else l /= 2;
            return;
        }
        l++;
        util(head->next, l, r, newhead);
        if (l != r) {
            if (newhead == nullptr) {
                newhead = head;
                newhead->next = nullptr;
            }
            else
            {
                head->next = newhead;
                newhead = head;
            }
        }
        ++r;
    }

    // Just for handling the problem with recursion
    ListNode* rdeleteMiddle(ListNode* head) {
        ListNode* newhead = nullptr;
        int l = 0;
        int r = 0;

        util(head, l, r, newhead);
        return newhead;
    }
    
    // This is the code in which I am solving the problem using the
    // Iterative approach
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = slow->next;
        else head = head->next;

        return head;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF