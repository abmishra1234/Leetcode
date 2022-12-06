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
    int findKthLargest(vector<int>& nums, int k) {
        PQ* pMinHeap = new PQ();
        for (int i = 0; i < min(k, (int)nums.size()); ++i) pMinHeap->push(nums[i]);

        if (k >= (int)nums.size()) return pMinHeap->top();

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] <= pMinHeap->top()) continue;
            pMinHeap->pop();
            pMinHeap->push(nums[i]);
        }
        
        return pMinHeap->top();
    }
};

Solution sln;

int main(void)
{
    vector<int> nums;
    int k;

    nums = { 2,1 };
    k = 1;

    int ans = sln.findKthLargest(nums, k);
    cout << ans << endl;


    return 0;
}

#endif // FORREF