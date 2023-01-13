// 379. Design Phone Directory
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

class PhoneDirectory {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* n) : val(x), next(n) {}
    };

    ListNode* head, * tail;

    void buildfreepool(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            ListNode* node = new ListNode(i);
            if (!head) head = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }

    // how to quickly check the number is in freepool or not?
    unordered_set<int> used;

    // For building this free pool, we are using the linklist
    PhoneDirectory(int maxNumbers) {
        tail = head = nullptr;
        // you should build your freepool
        buildfreepool(maxNumbers);
        used.clear();
    }

    int get() {
        if (!head) return -1;
        int ans = head->val;
        head = head->next;
        used.insert(ans);
        if (!head) tail = head;
        return ans;
    }

    bool check(int number) {
        if (used.find(number) != used.end()) return false;
        return true;
    }

    void release(int number) {
        auto it = used.find(number);
        if (it != used.end()) {
            ListNode* node = new ListNode(*it);
            if (!head) head = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }
            used.erase(it);
        }
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF