using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
#ifndef FORREF

#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string mergedString;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            mergedString += word1[i++];
            mergedString += word2[j++];
        }
        while (i < word1.size()) {
            mergedString += word1[i++];
        }
        while (j < word2.size()) {
            mergedString += word2[j++];
        }
        return mergedString;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF