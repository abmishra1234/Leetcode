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

//#define FORREF
#ifndef FORREF

class Solution {
public:
    
    void Util(const char* str, const int &l, int ind) {
        if (ind >= l) return;
        Util(str, l, ind + 1);
        cout << str[ind] << " ";
    }

    void printReverse(const char* str) {
        int l = strlen(str);
        Util(str, l, 0);
    }
};

Solution sln;

int main(void)
{
    sln.printReverse("ABiansh");
    return 0;
}

#endif // FORREF