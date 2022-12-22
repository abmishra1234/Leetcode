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

/*
    Union Find  or Disjoint Set Implementation
    Not yest completed , and complete this problem with Disjoint Set approach later...
*/
class UnionFind {
    typedef unordered_map<int, int> UMAP;
    UMAP parent;
    UMAP rank;

    int nvertices;
    
    void precompute(int n)
    {
        nvertices = n;
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
            rank[v] = 0;
        }
    }

    // returning the root of vertex set
    int Find(int v) {
        if (parent[v] != v) return Find(parent[v]);
        return v;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        precompute(n);

        for (int i = 0; i < dislikes.size(); ++i) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            int x = Find(u);
            int y = Find(v);

            if (x == y) return false;

            parent[u] = x;
            parent[v] = y;
        }
        return true;
    }
};




int main(void)
{

    return 0;
}

#endif // FORREF