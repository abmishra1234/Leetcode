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

/*
    Not yet completed problem.
*/

#define FORREF
#ifndef FORREF

class Solution {
public:
    void recRevereseStr(string &str, int l, int r) {
        if (l >= r) return;
        if (str[l] == str[r]) recRevereseStr(str, l + 1, r - 1);
        std::swap(str[l], str[r]);
        recRevereseStr(str, l + 1, r - 1);
    }

    void printReverse(const char* str) {
        if (!*str)
            return;
        recRevereseStr(str, 0, str.length() - 1);
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF