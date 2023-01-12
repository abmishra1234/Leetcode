/*
	725. Split Linked List in Parts
*/

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

class Solution {
public:
    void util(ListNode* head, const int &k, int nodecnt, vector<int> &svec, 
        ListNode*& newhead, deque<ListNode*> &nodes, int &pos) {
        if (!head)
        {
            cout << "nodecnt = " << nodecnt << endl; // 10
            cout << " k = " << k << endl; // k
            svec.resize(min(k, nodecnt), nodecnt / k);
            pos = min(k, nodecnt) - 1;
            nodecnt = nodecnt - (k * (nodecnt / k));
            for (int i = 0; i < k && nodecnt > 0; ++i) {
                svec[i] += 1;
                --nodecnt;
            }
            return;
        }
        ++nodecnt;
        util(head->next, k, nodecnt, svec, newhead, nodes, pos);
        // stack unwinding step
        if (pos >= 0)
        {
            if (svec[pos] > 0) {
                if (newhead == nullptr) {
                    newhead = head;
                    newhead->next = nullptr;
                }
                else
                {
                    head->next = newhead;
                    newhead = head;
                }
                svec[pos]--;
            }
            
            if (svec[pos] == 0 && newhead) {
                nodes.push_front(newhead);
                newhead = nullptr;
                --pos;
            }
        }
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        deque<ListNode*> nodes;
        vector<int> svec;
        ListNode* newhead = nullptr;
        int pos = k-1;
        int K = k;
        util(head, K, 0, svec, newhead, nodes, pos);
        
        // you will have to convert deque data into the vector data
        vector<ListNode*> ans;
        while (k-- > 0) {
            if (false == nodes.empty()) {
                ans.push_back(nodes.front());
                nodes.pop_front();
            }
            else
                ans.push_back({});
        }

        return ans;
    }
};

Solution sln;

int main(void)
{
    ListNode* head = nullptr;
    int k = 0;

    // #TC 1
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    k = 5;
    auto ans = sln.splitListToParts(head, k);

    // #TC 2
    head = nullptr;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    k = 3;
    auto ans1 = sln.splitListToParts(head, k);

	return 0;
}

#endif // FORREF
