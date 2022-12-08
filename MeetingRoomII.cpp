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

auto compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

typedef priority_queue<int, vector<int>, greater<int>> PQ;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort the input based on the first element of vector
        sort(intervals.begin(), intervals.end(), compare);

        PQ* pMinHeap = new PQ();
        for (auto v : intervals) {
            if (pMinHeap->empty()) pMinHeap->push(v[1]);
            else
            {
                if (v[0] >= pMinHeap->top()) pMinHeap->pop();
                pMinHeap->push(v[1]);
            }
        }
            
        return (int)pMinHeap->size();
    }
};

Solution sln;

int main(void)
{
    vector<vector<int>> input = { {7,10}, {2,4} };
    int ans = sln.minMeetingRooms(input);
    cout << "ans = " << ans << endl;
    return 0;
}

#endif // FORREF