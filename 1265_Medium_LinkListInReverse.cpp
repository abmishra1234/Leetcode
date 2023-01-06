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
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head) return;
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF