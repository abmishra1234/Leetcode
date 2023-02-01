/*
    https://leetcode.com/problems/binary-search-tree-iterator/description/
    https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=51
    
*/
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

struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class BSTIterator {
    vector<TreeNode*> arr;
    int pos = -1;
public:
    // Write your in-order traversal and populate the BST traversed set
    void solve(TreeNode* root) {
        if (!root) return;
        solve(root->left);
        arr.push_back(root);
        solve(root->right);
    }

    BSTIterator(TreeNode* root) {
        solve(root);
    }

    int next() {
        if (pos == -1) pos = 0;
        int num = arr[pos++]->val;
        return num;
    }

    bool hasNext() {
        int sz = arr.size();
        return (pos < sz) ? true : false;
    }
};

/*
    BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
    bSTIterator.next();    // return 3
    bSTIterator.next();    // return 7
    bSTIterator.hasNext(); // return True
    bSTIterator.next();    // return 9
    bSTIterator.hasNext(); // return True
    bSTIterator.next();    // return 15
    bSTIterator.hasNext(); // return True
    bSTIterator.next();    // return 20
    bSTIterator.hasNext(); // return False
*/

int main(void)
{
    TreeNode* root = new TreeNode(1);
    
    BSTIterator sln(root);

    bool flag = sln.hasNext();
    cout << flag << endl;

    int num = sln.next();
    cout << endl;

    flag = sln.hasNext();
    cout << flag << endl;





    return 0;
}

#endif // FORREF