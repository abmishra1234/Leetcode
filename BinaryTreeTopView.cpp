// https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
// https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24

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
template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Sorted map according to the col
typedef map<int, list<int>> MyMap;

vector<int> getTopView(TreeNode<int>* root) {
    if (!root) return {};

    deque<pair<int, TreeNode<int>*>> q;
    q.push_back({ 0,root });
    MyMap m;
    
    while (!q.empty()) {
        int qs = q.size();
        for (int i = 0; i < qs; ++i) {
            pair<int, TreeNode<int>*> p = q.front();
            q.pop_front();

            if (p.second->left)
                q.push_back({ p.first - 1, p.second->left });
            if(p.second->right)
                q.push_back({ p.first + 1, p.second->right });

            m[p.first].push_back(p.second->val);
        }
    }

    vector<int> ans;
    auto mit = m.begin();
    while (mit != m.end()) {
        if(mit->second.begin() != mit->second.end())
            ans.push_back(*mit->second.begin());
        ++mit;
    }
    
    return ans;
}

int main(void)
{

    return 0;
}

#endif // FORREF