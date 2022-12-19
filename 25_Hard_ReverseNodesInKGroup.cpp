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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* solve(ListNode* head, int k) {
        deque<ListNode*> q;

        ListNode* start = head;
        ListNode* prev = nullptr;
        int nodecount = 0;

        while (start) {
            prev = start;
            start = start->next;
            prev->next = nullptr;
            q.push_back(prev);
            ++nodecount;
        }

        int factor = nodecount / k;
        ListNode* newhead = nullptr, * tail = nullptr;

        while (factor > 0) {
            stack<ListNode*> s;
            for (int i = 0; i < k; ++i) {
                s.push(q.front());
                q.pop_front();
            }
            
            while (false == s.empty()) {
                ListNode* temp = s.top();
                s.pop();
                if (newhead == nullptr) {
                    newhead = tail = temp;
                }
                else
                {
                    tail->next = temp;
                    tail = tail->next;
                }
            }
            --factor;
        }

        while (false == q.empty()) {
            ListNode* temp = q.front();
            q.pop_front();
            if (newhead == nullptr) {
                newhead = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
        }

        return newhead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};

Solution sln;

int main(void)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    
    //---------------------

    ListNode* ans = sln.reverseKGroup(head, k);
    // ans : print will display - [2,1,4,3,5]
    
    cout << "[";
    while (ans) {
        cout << ans->val;
        if (ans->next != nullptr) cout << ",";
        ans = ans->next;
    }
    cout << "]" << endl;

    return 0;
}

#endif // FORREF