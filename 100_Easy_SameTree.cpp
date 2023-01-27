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
struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL)
            return true;
        else if (node1 == NULL || node2 == NULL)
            return false;

        return ((node1->val == node2->val) 
            && isSameTree(node1->left, node2->left) 
            && isSameTree(node1->right, node2->right));
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
