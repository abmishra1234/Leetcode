using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
#ifndef FORREF

/*
    The function getSkyline takes an input vector buildings representing the buildings in a city.
    The function creates an empty result vector result to store the key points of the skyline.
    It also creates a priority queue pq to keep track of the heights of the buildings.
    The variables currHeight and prevHeight are initialized to 0, i is initialized to 0, and x is initialized to 0.
    The while loop runs until either all buildings have been processed and the priority queue is empty.
    Inside the while loop, there are two cases to consider:
    If the priority queue is empty or the current building's left endpoint is less than or equal to the right endpoint of the building at the top of the priority queue, the current building is added to the priority queue.
    Otherwise, the building at the top of the priority queue has ended, so it is removed from the queue.
    After either case, the current height is updated based on the height of the building at the top of the priority queue, or set to 0 if the priority queue is empty.
    If the current height is different from the previous height, a new key point is added to the result vector.
    The function returns the result vector.
    The algorithm used in this code is similar to the one used in the previous code, but with a few modifications to optimize its performance. Instead of iterating over all the x-coordinates in the skyline, the code maintains a priority queue that keeps track of the buildings in the skyline. This reduces the time complexity of the algorithm from O(n^2) to O(n log n), where n is the number of buildings in the city.

*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>> pq;
        int currHeight = 0, prevHeight = 0, i = 0, x = 0;
        while (i < buildings.size() || !pq.empty()) {
            if (pq.empty() || (i < buildings.size() && buildings[i][0] <= pq.top().second)) {
                x = buildings[i][0];
                while (i < buildings.size() && buildings[i][0] == x) {
                    pq.push(make_pair(buildings[i][2], buildings[i][1]));
                    i++;
                }
            }
            else {
                x = pq.top().second;
                while (!pq.empty() && pq.top().second <= x) {
                    pq.pop();
                }
            }
            currHeight = pq.empty() ? 0 : pq.top().first;
            if (currHeight != prevHeight) {
                result.push_back({ x, currHeight });
                prevHeight = currHeight;
            }
        }
        return result;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF