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

#define FORREF
#ifndef FORREF
typedef priority_queue<int, vector<int>, greater<int>> PQ;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        PQ* pMinHeap = new PQ();
        for (auto s : sticks) pMinHeap->push(s);

        int cost = 0;

        while(pMinHeap->size() > 1) {
            int f = pMinHeap->top();
            pMinHeap->pop();
            int s = pMinHeap->top();
            pMinHeap->pop();

            pMinHeap->push(f + s);
            cost += (f + s);
        }

        return cost;
    }
};

int main(void)
{
    return 0;
}

#endif // FORREF