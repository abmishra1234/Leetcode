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
    Constraints:
    => maximum length after merging also upto 10^8

    3 <= list1.length <= 10^4
    1 <= a <= b < list1.length - 1 // making sure the range here
    1 <= list2.length <= 10^4

*/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h1 = list1;
        a--;
        while (h1 && a--) h1 = h1->next;
        ListNode* h2 = list1;
        while (h2 && (b-- >= 0)) h2 = h2->next;
        if (h1) {
            h1->next = list2;
            h1 = h1->next;
        }

        while (h1 && h1->next) {
            h1 = h1->next;
        }
        if(h1) h1->next = h2;
        return list1;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF