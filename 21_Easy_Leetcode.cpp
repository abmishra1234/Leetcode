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

// This is the structure of ListNode for merging the relevant code structure.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    void Util(ListNode* list1, ListNode* list2, ListNode** head, ListNode** tail) {
        // Base condtion we should right at the end
        if (list1 == nullptr && list2 == nullptr) return;
        else if (list1 && !list2) {
            if (*head == nullptr) {
                *head = *tail = list1;
                list1 = list1->next;
                (*tail)->next = nullptr;
            }
            else
            {
                (*tail)->next = list1;
                (*tail) = list1;
                list1 = list1->next;
                (*tail)->next = nullptr;
            }
        }
        else if (list2 && !list1) {
            if (*head == nullptr) {
                *head = *tail = list2;
                list2 = list2->next;
                (*tail)->next = nullptr;
            }
            else
            {
                (*tail)->next = list2;
                (*tail) = list2;
                list2 = list2->next;
                (*tail)->next = nullptr;
            }
        }
        else
        {
            // apart from base condtion what should be your code below

            if (*head == nullptr) {
                if (list1->val <= list2->val) {
                    *head = (*tail) = list1;
                    list1 = list1->next;
                    (*tail)->next = nullptr;
                }
                else
                {
                    *head = (*tail) = list2;
                    list2 = list2->next;
                    (*tail)->next = nullptr;
                }
            }
            else
            {
                if (list1->val <= list2->val) {
                    (*tail)->next = list1;
                    (*tail) = list1;
                    list1 = list1->next;
                    (*tail)->next = nullptr;
                }
                else
                {
                    (*tail)->next = list2;
                    (*tail) = list2;
                    list2 = list2->next;
                    (*tail)->next = nullptr;
                }
            }
        }
        Util(list1, list2, head, tail);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        Util(list1, list2, &head, &tail);
        return head;
    }
};
Solution sln;

int main(void)
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* res = sln.mergeTwoLists(list1, list2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}

#endif // FORREF