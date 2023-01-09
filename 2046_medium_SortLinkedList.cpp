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

/*
    Can you think of a solution with O(n) time complexity?
*/

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

class Solution {
public:
    // bcz it is iterative solution
    ListNode* isortLinkedList(ListNode* head) {
        ListNode* newhead = nullptr, *tail = nullptr;
        ListNode* start = head;
        while (start) {
            ListNode* node = start;
            start = start->next;
            node->next = nullptr;

            if (nullptr == newhead) {
                tail = newhead = node;
            }
            else
            {
                if (node->val < 0) {
                    node->next = newhead;
                    newhead = node;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                }
            }
        }
        return newhead;
    }
    
    void util(ListNode* head, ListNode* &newhead, ListNode* &tail) {
        if (!head) return;

        ListNode* node = head;
        head = head->next;
        node->next = nullptr;
        if (nullptr == newhead) {
            tail = newhead = node;
        }
        else
        {
            if (node->val < 0) {
                node->next = newhead;
                newhead = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
        util(head, newhead, tail);
    }
    
    
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* newhead = nullptr, * tail = nullptr;
        util(head, newhead, tail);
        return newhead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF