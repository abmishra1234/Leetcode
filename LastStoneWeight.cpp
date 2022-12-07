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

typedef priority_queue<int, vector<int>, less<int>> PQ;

class Solution {
protected:
    PQ* pMaxHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        int nStone = stones.size();
        if (nStone < 1) return 0;
        else if (nStone == 1) return stones[0];
        else
        {
            // So first of all push all the elements in maxheap
            pMaxHeap = new PQ();

            // add all the stones into the max heap
            for (auto stone : stones) pMaxHeap->push(stone);

            while (pMaxHeap->size() > 1) {
                int first = pMaxHeap->top();
                pMaxHeap->pop();
                int second = pMaxHeap->top();
                pMaxHeap->pop();

                if (first == second) continue;
                else {
                    pMaxHeap->push(first - second);
                }
            }
            
            if (pMaxHeap->size() == 0) return 0;
            else return pMaxHeap->top();
        }
    }
};


int main(void)
{


    return 0;
}

#endif // FORREF