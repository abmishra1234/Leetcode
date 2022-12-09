using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>

#define FORREF
#ifndef FORREF
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* start = nullptr;
        ListNode** tHead = &start;

        while (head)
        {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = nullptr;
            // addd the node into the tHead
            if (*tHead == nullptr)
            {
                *tHead = tmp;
            }
            else
            {
                tmp->next = *tHead;
                *tHead = tmp;
            }
        }
        return *tHead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF