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
    void solve(vector<char>& arr, int l, int r)
    {
        if (l >= r)
            return;
        char t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        solve(arr, l + 1, r - 1);
    }

public:
    void reverseString(vector<char>& s) {
        solve(s, 0, s.size() - 1);
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF