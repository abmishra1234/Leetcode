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

//#define FORREF
#ifndef FORREF
/*
    1. Your code should work for Cyclic case also
    2. Incase cycle the order decision is not possible and
    so, your output of this test case is empty string ("").
    3. Let's discuss now for the case when your given test case 
     is non cyclic and directed(DAG).

    in this case our solution approach would be 
    just try to find the topological sorted order of 
    vertex
*/

class Solution {
public:

    /*
        Let's write the comment for the feature of your method
        1. Finding the cycle if any and return
        2. Finding the topological sort order
    */
    void dfs(int u, vector<int>& vis,
        vector<int>& vispath, stack<int>& s, bool& cycle,
        vector<vector<int>>& adj) {
        vis[u] = 1;
        vispath[u] = 1;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, vis, vispath, s, cycle, adj);
            }
            else if (vispath[v]) {
                cycle = true;
                return;
            }
        }
        vispath[u] = 0;
        s.push(u);
    }

    string alienOrder(vector<string>& words) {
        // The first thing you should do to build the adjacency list
        // out of given word in test case
        // Step 01 - Extract the Edge, 
        vector<vector<int>> adj(26, vector<int>());
        vector<int> charcache(26, 0);

        for (int i = 1; i < words.size(); ++i) {
            for (int j = 0; j < min(words[i - 1].size(), words[i].size()); ++j) {
                if (words[i - 1].at(j) == words[i].at(j)) continue;
                else {
                    // you found the edge
                    adj[words[i - 1].at(j) - 'a'].push_back(words[i].at(j) - 'a');
                    charcache[words[i - 1].at(j) - 'a'] = 1;
                    charcache[words[i].at(j) - 'a'] = 1;
                    break; // go outside from internal for loop
                }
            }
        }

        bool empty = true;
        for (int i = 0; i < 26; ++i) {
            if (charcache[i]) {
                empty = false;
                break;
            }
        }

        if (empty) return words[0];

        vector<int> vis(26, 0);
        vector<int> vispath(26, 0);
        stack<int> s;
        bool cycle = false;

        for (int i = 0; i < 26; ++i) {
            if (!vis[i] && charcache[i]) {
                cycle = false;
                dfs(i, vis, vispath, s, cycle, adj);
                if (cycle) return "";
            }
        }

        string ans = "";
        while (!s.empty()) {
            ans += (char)(s.top() + 'a');
            s.pop();
        }
        return ans;
    }
};

Solution sln;

int main(void)
{
    vector<string> words;
    string ans;

    words = {"z", "z"};
    ans = sln.alienOrder(words);

    return 0;
}

#endif // FORREF