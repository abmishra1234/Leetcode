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
/*
    This code defines a singly-linked list structure ListNode and a function partition that takes a linked list and an integer x as input, 
    and partitions the list around the value x. The function creates two new lists: one for nodes with values less than x, and another 
    for nodes with values greater than or equal to x. It then traverses the original list, adding each node to either the "less than x" list 
    or the "greater than or equal to x" list. Finally, it merges the two lists and returns the result.
    The code also includes some test cases to demonstrate how the partition function works.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Partition a linked list around a given value x
ListNode* partition(ListNode* head, int x) {
    ListNode* less = new ListNode(0);
    ListNode* greater = new ListNode(0);
    ListNode* p = head, * p1 = less, * p2 = greater;

    while (p) {
        if (p->val < x) {
            p1->next = p;
            p1 = p1->next;
        }
        else {
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    p2->next = nullptr;
    p1->next = greater->next;
    return less->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    ListNode* result = partition(head, x);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 1 2 2 4 3 5

    // Test empty list
    ListNode* empty = nullptr;
    result = partition(empty, x);
    if (!result) cout << "Empty list" << endl; // Output: Empty list

    // Test list with only one node
    ListNode* single = new ListNode(2);
    result = partition(single, x);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 2

    return 0;
}


#endif // FORREF