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
    int minDeletionSize(vector<string>& strs) {
        int R = strs.size();
        int C = strs[0].size();

        int delcnt = 0;

        for (int i = 0; i < C; ++i) {
            for (int j = 1; j < R; ++j) {
                if (strs[j][i] < strs[j - 1][i]) {
                    ++delcnt; break;
                }
            }
        }
        return delcnt;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF