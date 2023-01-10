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
    void Solve(string& str, int pos, vector<string>& ans)
    {
        if (pos >= str.length()) {
            ans.push_back(str);
            return;
        }

        for (int i = pos; i < str.size(); ++i)
        {
            swap(str[i], str[pos]);
            Solve(str, pos + 1, ans);
            swap(str[i], str[pos]);
        }
    }

    vector<string> generatePermutations(string& str)
    {
        // write your code here
        vector<string> ans;
        Solve(str, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF