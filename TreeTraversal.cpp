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
/*
    Key learning from this exercise is 
    one how to write the recursive tree traversing,
    which is super easy

    Another key learning, incase you want to avoid to write the code recursively
    than what should you sdo to write this iteratively.
*/


template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(BinaryTreeNode<int>* root, vector<int>& pre) {
    if (!root) return;
    pre.push_back(root->data);
    preorder(root->left, pre);
    preorder(root->right, pre);
}

void ipreorder(BinaryTreeNode<int>* root, vector<int>& pre) {
    if (!root) return;
    stack<BinaryTreeNode<int>*> s;
    s.push(root);

    while (!s.empty()) {
        BinaryTreeNode<int>* np = s.top();
        pre.push_back(np->data);
        s.pop();
        // RL
        if (np->right) s.push(np->right);
        if (np->left) s.push(np->left);
    }
}


void postorder(BinaryTreeNode<int>* root, vector<int>& post) {
    if (!root) return;
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data);
}

void ipostorder(BinaryTreeNode<int>* root, vector<int>& post) {
    if (!root) return;
    stack<BinaryTreeNode<int>*> s;
    stack<int> ss; // second stack
    s.push(root);

    while (!s.empty()) {
        BinaryTreeNode<int>* np = s.top();
        s.pop();
        ss.push(np->data);
        // RL
        if (np->left) s.push(np->left);
        if (np->right) s.push(np->right);
    }

    while (!ss.empty()) {
        post.push_back(ss.top()); ss.pop();
    }
}



void inorder(BinaryTreeNode<int>* root, vector<int>& in) {
    if (!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int>* root) {
    // Different type of tree traversal

    vector<int> pre;
    vector<int> post;
    vector<int> in;

    preorder(root, pre);
    postorder(root, post);
    inorder(root, in);

    vector<vector<int>> ans;
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    
    return ans;
}


int main(void)
{

    return 0;
}

#endif // FORREF