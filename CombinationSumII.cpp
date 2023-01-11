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
    // 1  : Yes, this problem is solved based on recursion
    void Solve(vector<int>& arr, int n, int i, int target, vector<int>& subset, vector<vector<int>>& ans)
    {

        // 4 . base condition
        if (target < 0) return;

        if (target == 0)
        {
            ans.push_back(subset);
            return;
        }

        if (i >= n)
            return;

        // 2 : Do the small task
        // pick the ith element
        subset.push_back(arr[i]);
        Solve(arr, n, i + 1, target - arr[i], subset, ans); // 3

        subset.pop_back(); // backtrack step

        while (i + 1 < n && arr[i] == arr[i + 1]) ++i;
        Solve(arr, n, i + 1, target, subset, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int n, int target)
    {
        // Write your code here.
        sort(arr.begin(), arr.end());
        vector<int> subset;
        vector<vector<int>> ans;
        Solve(arr, n, 0, target, subset, ans);
        //    sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF