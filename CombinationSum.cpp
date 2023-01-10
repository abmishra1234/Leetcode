using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

#define FORREF
#ifndef FORREF
class Solution {
public:
    void Solve(int pos, int n, int k, vector<int>& subset, vector<vector<int>>& ans)
    {
        if (n - pos + 1 < k) return;

        if (k == 0) {
            ans.push_back(subset);
            return;
        }

        if (pos > n) return;

        // Do the small task - 2
        // take the pos element
        subset.push_back(pos);
        Solve(pos + 1, n, k - 1, subset, ans);

        // skip the pos element
        subset.pop_back();
        Solve(pos + 1, n, k, subset, ans);
    }

    vector<vector<int>> combinations(int n, int k)
    {
        // Write your code here.
        vector<int> subset;
        vector<vector<int>> ans;
        Solve(1, n, k, subset, ans);
        return ans;
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF