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
    void solve(vector<int>& arr, int l, int r)
    {
        if (l >= r) return;
        solve(arr, l + 1, r - 1);
        swap(arr[l], arr[r]);
    }

    void reverseArray(vector<int>& arr, int m)
    {
        solve(arr, m + 1, arr.size() - 1);
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF