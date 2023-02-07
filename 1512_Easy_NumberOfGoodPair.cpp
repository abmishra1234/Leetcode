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

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }

        int ans = 0;

        auto it = m.begin();
        while (it != m.end()) {
            if (it->second > 1) {
                ans += ((it->second * (it->second - 1)) / 2);
            }
        }
        return ans;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF