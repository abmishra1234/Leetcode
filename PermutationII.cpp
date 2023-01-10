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
    https://bit.ly/39SpX1X
*/
#define FORREF
#ifndef FORREF
class Solution {
public:
    void Solve(vector<int>& v, int pos, vector<vector<int>>& ans)
    {
        if (pos >= v.size()) {
            ans.push_back(v);
            return;
        }
        unordered_set<int> cache;
        for (int i = pos; i < v.size(); ++i)
        {
            if (cache.find(v[i]) != cache.end())
                continue;
            cache.insert(v[i]);
            swap(v[i], v[pos]);
            Solve(v, pos + 1, ans);
            swap(v[i], v[pos]);
        }
    }

    vector<vector<int> > uniquePermutations(vector<int>& arr, int n) {
        // Write your code here.
        vector<vector<int>> ans;
        Solve(arr, 0, ans);
        return ans;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF