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
    ListNode* mergeNodes(ListNode* h) {
        ListNode* head = nullptr, * tail = nullptr;
        int sum = 0;

        ListNode* start = h;
        bool collect = false;
        while (start) {
            if (start->val == 0) {
                if (sum <= 0) {
                    start = start->next;
                    continue;
                }
                if (!head) {
                    head = tail = new ListNode(sum);
                }
                else
                {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }
                sum = 0;
            }
            else {
                sum += start->val;
            }
            start = start->next;

            if (!start && sum > 0) {
                if (!head) {
                    head = tail = new ListNode(sum);
                }
                else
                {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }
                break;
            }
        }
        return head;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF