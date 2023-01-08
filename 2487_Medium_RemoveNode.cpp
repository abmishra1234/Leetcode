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

class Solution {
public:
    void Util(ListNode* head, int &val, ListNode* &newhead) {
        if (!head) return;
        Util(head->next, val, newhead);
        
        if (head->val >= val) {
            // than i have to pick this node
            val = head->val;
            if (newhead == nullptr) {
                head->next = nullptr;
                newhead = head;
            }
            else
            {
                head->next = newhead;
                newhead = head;
            }
        }
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* newhead = nullptr;
        int val = -1;
        Util(head, val, newhead);
        return newhead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF