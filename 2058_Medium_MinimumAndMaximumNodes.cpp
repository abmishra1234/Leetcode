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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    typedef pair<int, int> pii; // < value, position >
    // For your custom sorting
    struct MySort {
        auto operator()(const pii& a, const pii& b) const {
            return a.second < b.second;
        }
    };

    void util(ListNode* head, int pos, stack<pii>& prev,
        stack<pii>& next, vector<pii>& cp /* critical points*/)
    {
        if (!head) return;
        prev.push({ head->val, pos });
        util(head->next, pos + 1, prev, next, cp);
        
        // stack unwinding step
        if (prev.size() > 0) {
            pii curr = prev.top();
            prev.pop();

            if (prev.size() > 0 && next.size() > 0) {
                pii t1 = prev.top();
                pii t2 = next.top();

                if (curr.first > t1.first && curr.first > t2.first
                    || (curr.first < t1.first && curr.first < t2.first)) {
                    cp.push_back(curr);
                }
            }
            next.push(curr);
        }
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        stack<pii> prev;
        stack<pii> next;
        vector<pii> cp;

        util(head, 1, prev, next, cp);
        if (cp.size() == 0 || cp.size() == 1) return { -1, -1 };

        // now find the min and max distance
        sort(cp.begin(), cp.end(), MySort());
        
        int mind = INT_MAX, maxd = INT_MIN;
        
        int vs = (int) cp.size();
        maxd = max(cp[vs - 1].second - cp[0].second, maxd);

        for (int i = 1; i < vs; ++i) {
            mind = min(mind, cp[i].second - cp[i - 1].second);
        }

        return {mind, maxd};
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF