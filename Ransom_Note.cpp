/*
    Solve the below problem.
*/

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
    unordered_map<char, int> umap;
    bool canConstruct(string ransomNote, string magazine) {
        umap.clear();

        // put all the chars into map
        for (char ch : ransomNote) {
            umap[ch] += 1;
        }

        // next loop
        for (char ch : magazine) {
            auto it = umap.find(ch);
            if (it != umap.end()) {
                umap[ch] -= 1;
            }
        }

        for (auto it = umap.begin(); it != umap.end(); ++it) {
            if (it->second > 0)
                return false;
        }

        return true;
    }
};

#endif // 0