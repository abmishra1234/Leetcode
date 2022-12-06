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
    vector<int> TopKElements(vector<int>& input, int K) {
        // Let's create the min heap
        PQ *pMinHeap = new PQ();
        // now push the k element into the min heap

        for (int i = 0; i < K; ++i) {
            pMinHeap->push(input[i]);
        }

        for (int i = K; i < input.size(); ++i) {
            if (input[i] <= pMinHeap->top()) continue;
            else
            {
                pMinHeap->pop();
                pMinHeap->push(input[i]);
            }
        }

        vector<int> output;

        while (pMinHeap->empty() == false) {
            output.push_back(pMinHeap->top());
            pMinHeap->pop();
        }
        return output;
    }
};

Solution sln;

int main(void)
{


    return 0;
}

#endif // FORREF