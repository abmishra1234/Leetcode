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
    void solve(vector<int>& v, int pos, vector<int> subset, vector<vector<int>>& ans)
    {
        if (pos >= v.size()) {
            ans.push_back(subset);
            return;
        }

        // include the element
        subset.push_back(v[pos]);
        solve(v, pos + 1, subset, ans);
        subset.pop_back();
        solve(v, pos + 1, subset, ans);
    }

    vector<vector<int>> pwset(vector<int>v)
    {
        //Write your code here
        vector<vector<int>> ans;
        vector<int> subset;
        solve(v, 0, subset, ans);
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF