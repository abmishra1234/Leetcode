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

/*
    summary: 
    Not completed

    @Note:
    May be the problem not understood by me properly.
    So, I should re work on this problem after some time today...
*/
#define FORREF
#ifndef FORREF

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";
        unordered_map<char, unordered_set<char>>graph;
        unordered_map<char, int>degree;
        for (auto x : words) for (auto c : x) degree[c] = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i], b = words[i + 1];
            for (int j = 0; j < min(a.size(), b.size()); j++) {
                if (a[j] == b[j]) continue;
                if (!graph[a[j]].count(b[j])) {
                    graph[a[j]].insert(b[j]);
                    degree[b[j]]++;
                }
                break;
            }
        }
        string res = "";
        while (true) {
            char c = '#';
            for (auto x : degree)
                if (x.second == 0) c = x.first;
            if (c == '#') break;
            degree[c] = -1;
            for (auto neigh : graph[c])
                degree[neigh]--;
            res += c;
        }
        if (res.size() != degree.size()) return "";
        return res;
    }
};

Solution sln;

int main(void)
{
    vector<string> words = { "z","x","z" };
    string ans = sln.alienOrder(words);
    cout << ans << endl;

    return 0;
}

#endif // FORREF