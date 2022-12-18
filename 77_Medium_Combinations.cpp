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

class Solution {
    void Solve(int pos, int n, int k, 
        vector<int>& subset, vector<vector<int>>& ans)
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

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;
        Solve(1, n, k, subset, ans);
        return ans;
    }
};

Solution sln;

int main(void)
{
    vector<vector<int>> ans;
    int n, k;

    // #1
    n = 4, k = 2;
    ans = sln.combine(n, k);
    
    cout << "[";
    for (auto v : ans) {
        cout << "[";
        for (auto elem : v)
            cout << elem << " ";
        cout << "]";
    }
    cout << "]";
    cout << endl;

    // #2
    n = 1, k = 1;
    ans = sln.combine(n, k);
    cout << "[";
    for (auto v : ans) {
        cout << "[";
        for (auto elem : v)
            cout << elem << " ";
        cout << "]";
    }
    cout << "]";
    cout << endl;

    return 0;
}

#endif // FORREF