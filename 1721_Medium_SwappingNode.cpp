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
    void util(ListNode* &head, int k, int &i, ListNode* &kNode) {
        if (!head) {
            i = k;
            return;
        }
        --i;
        if (i == 0) {
            kNode = head;
        }

        util(head->next, k, i, kNode);
        --i;
        // now it's time to stack unwind 
        if (i == 0) {
            int temp = kNode->val;
            kNode->val = head->val;
            head->val = temp;
        }
    }


    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kNode = nullptr;
        util(head, k, k, kNode);
        return head;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF