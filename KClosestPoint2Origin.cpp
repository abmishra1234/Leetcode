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

typedef pair<int, pair<int, int>> p3i;
struct MyCmp {
    auto operator()(const p3i& a, const p3i& b) const {
        return a.first < b.first;
    }
};

typedef priority_queue<p3i, vector<p3i>, MyCmp> PQ;

class Solution {
public:
    int GetDist(int x, int y) {
        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        PQ* pMaxHeap = new PQ();
        int i = 0;
        for (; i < k; ++i) {
            pMaxHeap->push({ GetDist(points[i][0], points[i][1]), 
                {points[i][0], points[i][1]} });
        }
        
        for (; i < points.size(); ++i) {
            int d = GetDist(points[i][0], points[i][1]);
            if (d >= pMaxHeap->top().first) continue;
            else {
                pMaxHeap->pop();
                pMaxHeap->push({ d, {points[i][0], points[i][1]} });
            }
        }
        vector<vector<int>> out;
        vector<int> v(2, -1);
        
        while (pMaxHeap->empty() == false) {
            v[0] = pMaxHeap->top().second.first;
            v[1] = pMaxHeap->top().second.second;
            out.push_back(v);
            pMaxHeap->pop();
        }
        return out;
    }
};

Solution sln;

int main(void)
{
    return 0;
}

#endif // FORREF