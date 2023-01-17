/*
 
    1443. Minimum Time to Collect All Apples in a Tree
    https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
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
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

#define FORREF
#ifndef FORREF

class Solution {
public:
    void dfs(int src, vector<bool>& vis, 
        deque<pair<int, int>> &s, vector<vector<int>>& edges,
        vector<bool>& hasApple) {
        vis[src] = true;

        // check the all possible path
        for (auto dest : edges[src]) {
            if (!vis[dest]) {
                s.push_front({ src, dest });
                dfs(dest, vis, s, edges, hasApple);
                if (!hasApple[dest]) {
                    s.pop_front();
                }
            }
        }
    }
    /*
        n  is the number of vertices - {0, n-1}
        Write normal dfs code to collect all the apples,
        only thing is to cater that you have to go
        on that path only where you will see the apple
    */
    int minTime(int n, vector<vector<int>>& edges, 
        vector<bool>& hasApple) {
        
        vector<bool> vis(n, false);
        deque<pair<int, int>> s;

        dfs(0, vis, s, edges, hasApple);

        return s.size();
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF