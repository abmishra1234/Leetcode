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
    void util(ListNode* head, unordered_map<int, int>& m, ListNode*& newhead) {
        if (!head) return;

        auto it = m.find(head->val);
        if (it == m.end()) m[head->val] = 1;
        else m[head->val] += 1;

        util(head->next, m, newhead);
        
        // now do some tack on the stack unwinding step
        if (m[head->val] == 1) {
            // this is not the duplicate case
            if (newhead = nullptr) {
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

    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> m;
        m.clear();

        ListNode* newhead = nullptr;
        util(head, m, newhead);
        return newhead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF