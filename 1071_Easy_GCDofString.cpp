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
public:
    string gcdOfStrings(string str1, string str2) {
        if ((str1 + str2).compare(str2 + str1) != 0) return "";
        else if (str1.compare(str2) == 0) return str1;
        else if (str1.length() > str2.length()) {
            return gcdOfStrings(str1.substr(str2.length()), str2);
        }
        else {
            return gcdOfStrings(str2.substr(str1.length()), str1);
        }
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF