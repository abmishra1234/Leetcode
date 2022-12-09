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

/*
    1 <= heights.length <= 10^5
    1 <= heights[i] <= 10^6
    0 <= bricks <= 10^9
    0 <= ladders <= heights.length      
*/

typedef priority_queue<int, vector<int>, greater<int>> MinHeap;

#define FORREF
#ifndef FORREF
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 1;
        int depth;
        MinHeap* pHeap = new MinHeap();

        for (; i < heights.size(); ++i) {
            depth = heights[i] - heights[i - 1];
            if (depth <= 0) continue;

            if (ladders == 0 && bricks == 0) break;

            if (ladders > 0) {
                --ladders;
                pHeap->push(depth);
                continue;
            }

            if (pHeap->empty() == false && depth > pHeap->top()) {
                int prev = pHeap->top();
                pHeap->pop();
                pHeap->push(depth);
                if (prev <= bricks)
                    bricks -= prev;
                else
                    break;
                continue;
            }
            else
            {
                if (depth <= bricks) {
                    bricks -= depth;
                    continue;
                }
                else
                    break;
            }
        }
        return i - 1;
    }
};

int main(void)
{


    return 0;
}

#endif // FORREF