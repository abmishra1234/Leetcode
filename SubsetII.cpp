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

/*
    https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236
*/
#define FORREF
#ifndef FORREF

class Solution {
public:
    // utility method for solving the all unique subset problem
    void solve(vector<int>& arr, int pos, vector<int> subset, vector<vector<int>>& ans)
    {
        if (pos >= arr.size()) {
            ans.push_back(subset);
            return;
        }

        // pick
        subset.push_back(arr[pos]);
        solve(arr, pos + 1, subset, ans);
        // back trace
        subset.pop_back();

        // skip for duplicate
        while (pos + 1 < arr.size() && arr[pos] == arr[pos + 1]) pos++;

        solve(arr, pos + 1, subset, ans);
    }

    vector<vector<int>> uniqueSubsets(int n, vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> subset;
        solve(arr, 0, subset, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
