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

/*
    Approach 01 : One solution which is recursive??

*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    void util(ListNode* head, vector<pair<ListNode*, ListNode*>> &v) {
        if (!head) return;
        util(head->next, v);
        // stack unwinding step
        int val = abs(head->val);
        if (v[abs(val)].first == nullptr) {
            head->next = nullptr;
            v[abs(val)].first = v[abs(val)].second = head;
        }
        else
        {
            if (val < 0) {
                // add before head
                head->next = v[abs(val)].first;
                v[abs(val)].first = head;
            }
            else
            {
                //add after tail
                head->next = nullptr;
                v[abs(val)].second->next = head;
                v[abs(val)].second = head;
            }
        }
    }

    ListNode* sortList(ListNode* head) {
        vector<pair<ListNode*, ListNode*>> vlist;
        const int maxsize = 100001;
        vlist.resize(maxsize, { nullptr, nullptr });
        
        util(head, vlist);
        
        // Merging step of linklist in final ont linklist
        ListNode* newhead = nullptr, *tail = nullptr;
        for (int i = 0; i < maxsize; ++i) {
            if (vlist[i].first) {
                // it means this has some node to be collected in final list
                ListNode* start = vlist[i].first;
                while (start) {
                    ListNode* next = start->next;
                    if (!newhead) {
                        start->next = nullptr;
                        newhead = tail = start;
                    }
                    else
                    {
                        if (start->val < 0) {
                            // add new node before head
                            start->next = newhead;
                            newhead = start;
                        }
                        else
                        {
                            // add new node after the head
                            start->next = nullptr;
                            tail->next = start;
                            tail = start;
                        }
                    }
                    start = next;
                }
            }
        }
        return newhead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF