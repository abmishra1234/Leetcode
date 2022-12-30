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
    bool validPalindrome(string s) {
        bool skip = true;
        bool tryagain = false;
        int i = 0, j = s.length() - 1;

        int bkp_i, bkp_j;

        while (i < j) {
            if (s.at(i) != s.at(j)) {
                // case 01
                if (skip && !tryagain) {
                    bkp_j = j;
                    bkp_i = i;
                    j--;
                    skip = false;
                    tryagain = true;
                    continue;
                }
                else if (!skip && tryagain) {
                    i = bkp_i;
                    j = bkp_j;
                    tryagain = false;
                    ++i;
                    continue;
                }
                else
                    return false;
            }
            ++i, --j;
        }
        return true;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF