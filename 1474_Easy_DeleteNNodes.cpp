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
    void util(ListNode*& head, int m, int n) {
        if (!head) return;
        // do the small task as suggested in problem
        int i = 1;
        while (i <= m) head = head->next;
        ListNode* fh = head;
        i = 1;
        while (i <= n) head = head->next;
        fh->next = head->next;
        // Let the recursion do the rest task
        util(head->next, m, n);
    }

    ListNode* deleteNodes(ListNode* head, int m, int n) {
        util(head, m, n);
        return head;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF