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
    void Util(ListNode* head, ListNode* &bkphead, int& maxsum) {
        if (!head) return;
        Util(head->next, bkphead, maxsum);
        maxsum = max(maxsum, (bkphead->val + head->val));
        bkphead = bkphead->next;
    }

    int pairSum(ListNode* head) {
        ListNode* bkphead = head;
        int maxsum = INT_MIN;
        Util(head, bkphead, maxsum);
        return maxsum;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF