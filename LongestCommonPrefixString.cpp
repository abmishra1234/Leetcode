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
    string longestCommonPrefix(vector<string>& strs) {
        string out = "";
        bool match = true;

        for (int j = 0; j < strs[0].length(); ++j) {
            for (int i = 1; i < strs.size(); ++i) {
                if (j >= strs[i].length() || strs[0][j] != strs[i][j]) {
                    match = false;
                }
            }
            if (match == false) break;
            out += strs[0][j];
        }
        return out;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF