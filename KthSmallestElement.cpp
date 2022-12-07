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
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        PQ* pMaxHeap = new PQ();
        int R = (int)matrix.size(), C = (int)matrix[0].size();

        int i = 0, r = 0, c = 0;
        while (i < k) {
            r = i / R;
            c = i % C;
            pMaxHeap->push(matrix[r][c]);
            ++i;
        }

        while (i < (R * C)) {
            r = i / R;
            c = i % C;
            ++i;
            if (matrix[r][c] >= pMaxHeap->top()) continue;
            else
            {
                pMaxHeap->pop();
                pMaxHeap->push(matrix[r][c]);
            }
        }
        
        return pMaxHeap->top();
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF