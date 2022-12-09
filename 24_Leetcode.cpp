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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
 class Solution {
public:

    ListNode* swapPairs(ListNode* head) {
        // As per constraint number of nodes might be 0, 1 or more
        if (!head || (head && !head->next)) return head;
        
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr && curr->next) {
            next = curr->next;

            int temp = curr->val;
            curr->val = next->val;
            next->val = temp;
            curr = curr->next->next;
        }

        return head;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF