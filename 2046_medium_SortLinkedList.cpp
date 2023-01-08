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

/*
    Sorting with insertion sort will not work here??
    Giving TLE
    Why? because the number of node is upto 10^5

    Follow up:
    Can you think of a solution with O(n) time complexity?
*/

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
    void util(ListNode* head, vector<int> &v) {
        if (!head) {
            sort(v.begin(), v.end(), greater<int>());
            return;
        }
        v.push_back(head->val);
        util(head->next, v);

        // task to do while stack unwinding
        head->val = v[0];
        v.erase(v.begin());
    }

    ListNode* sortLinkedList(ListNode* head) {
        int elem = -5001;
        ListNode* start = head;
        int cnt = 0;
        while (start) {
            if (elem != start->val) {
                elem = start->val;
                ++cnt;
            }
            start = start->next;
        }

        if (cnt == 1) return head;

        vector<int> v;
        util(head, v);
        return head;
    }
};




int main(void)
{

    return 0;
}

#endif // FORREF