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
    int minimumRounds(vector<int>& tasks) {
        // first sort this array
        sort(tasks.begin(), tasks.end());

        int i = 0;
        int count = 0;
        int val = tasks[0];
        int ans = 0;

        while (i < tasks.size()) {
            if (val == tasks[i]) {
                count++;
            }

            else {
                val = tasks[i];
                if (count <= 1) return -1;
                ans += (count + 2) / 3;
                count = 1;
            }

            if (i == tasks.size() - 1) {
                if (count <= 1) return -1;
                ans += (count + 2) / 3;
                break;
            }
            ++i;
        }
        return ans;
    }
};

Solution sln;

int main(void)
{



    return 0;
}

#endif // FORREF