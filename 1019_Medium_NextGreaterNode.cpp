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

//#define FORREF
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* start = head;
        while (start) {
            arr.push_back(start->val);
            start = start->next;
        }

        stack<int> s;
        vector<int> output;
        output.resize(arr.size(), 0);

        for (int i = 0; i < arr.size(); ++i) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                int pos = s.top();
                output[pos] = arr[i];
                s.pop();
            }
            s.push(i);
        }

        return output;
    }
};

Solution sln;

int main(void)
{
    ListNode* head = new ListNode(9);
    head->next = new ListNode(7);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(9);

    //ListNode* head = new ListNode(2);
    //head->next = new ListNode(1);
    //head->next->next = new ListNode(5);
    //head->next->next->next = new ListNode(1);

    auto out = sln.nextLargerNodes(head);
    for (auto n : out) cout << n << " ";
    cout << endl;

    return 0;
}

#endif // FORREF