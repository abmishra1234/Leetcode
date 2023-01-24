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

template <typename T>
class BinaryTreeNode {
public:
    T val;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
/*
    Small tweak in BFS for producing the level order
*/

vector<int> getLevelOrder(BinaryTreeNode<int>* root)
{
    deque<BinaryTreeNode<int>*> q;
    vector<int> ans;

    if (!root) return {};
    q.push_back(root);

    while (!q.empty()) {
        int qs = q.size();
        for (int i = 0; i < qs; ++i) {
            auto np = q.front(); q.pop_front();
            if (np->left) q.push_back(np->left);
            if (np->right) q.push_back(np->right);
            ans.push_back(np->val);
        }
    }
    return ans;
}


int main(void)
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->left->right = new BinaryTreeNode<int>(7);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(6);

    auto ans = getLevelOrder(root);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

#endif // FORREF
