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
    
    //-------------

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
    typedef unordered_set<int> MySet;
public:
    MySet s;
    int numComponents(ListNode* head, vector<int>& nums) {
        s.clear();
        for (auto elem : nums) s.insert(elem);

        int cnt = 0;
        bool comp = false;
        while (head) {
            if (s.find(head->val) != s.end()) {
                if (!comp) comp = true;
            }
            else
            {
                if (comp) {
                    ++cnt;
                    comp = false;
                }
            }
            head = head->next;
        }
        if (comp) ++cnt;
        return cnt;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF