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

class KthLargest {
    PQ* pMinHeap;
    int K;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        pMinHeap = new PQ();
        int nl = nums.size();
        int i = 0;
        for (; i < min(k, nl); ++i) {
            pMinHeap->push(nums[i]);
        }
        
        for (i = k; i < nl; ++i) {
            if (nums[i] <= pMinHeap->top()) continue;
            pMinHeap->pop();
            pMinHeap->push(nums[i]);
        }
    }

    int add(int val) {
        if (pMinHeap->empty())
        {
            pMinHeap->push(val);
            return val;
        }

        if ((int)pMinHeap->size() < K) {
            pMinHeap->push(val);
            return pMinHeap->top();
        }

        if (val <= pMinHeap->top()) return pMinHeap->top();
        else
        {
            pMinHeap->pop();
            pMinHeap->push(val);
        }
        
        return pMinHeap->top();
    }
};

int main(void)
{


    return 0;
}

#endif // FORREF