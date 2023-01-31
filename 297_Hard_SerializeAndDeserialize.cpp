/*
    Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
    Ref Video : https://www.youtube.com/watch?v=-YbXySKJsX8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=37
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

class Codec {
public:

    // Encodes a tree to a single string.
    // Let's do this by using the level order traversal
    string serialize(TreeNode* root) {
        string output = "";
        if (!root) return output;

        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            TreeNode* np = q.front();
            q.pop_front();
            if (np == nullptr) {
                output += "#";
            }
            else
            {
                output += to_string(np->val);
                q.push_back(np->left);
                q.push_back(np->right);
            }
            output += ',';
        }
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* newRoot = nullptr;
        if (data.empty()) return newRoot;

        int strind = 0;
        deque<TreeNode*> q;

        string num = "";
        int val = 0;

        while (data.at(strind) != ',') {
            num += data.at(strind++);
        }
        ++strind;
        val = stoi(num);
        newRoot = new TreeNode(val);
        q.push_back(newRoot);
        
        while (!q.empty()) {
            TreeNode* np = q.front();
            q.pop_front();

            // first child
            num = "";
            val = 0;

            while (data.at(strind) != ',') {
                num += data.at(strind++);
            }
            ++strind;

            if (num[0] == '#') np->left = nullptr;
            else {
                val = stoi(num);
                np->left = new TreeNode(val);
                q.push_back(np->left);
            }

            // second child
            num = "";
            val = 0;

            while (data.at(strind) != ',') {
                num += data.at(strind++);
            }
            ++strind;

            if (num[0] == '#') np->right = nullptr;
            else {
                val = stoi(num);
                np->right = new TreeNode(val);
                q.push_back(np->right);
            }
        }

        return newRoot;
    }

    // for testing the Tree Construction 
    void print_inorder(TreeNode* root) {
        if (!root) return;
        print_inorder(root->left);
        cout << root->val << ",";
        print_inorder(root->right);
    }

};

Codec sln;

// For your Logic verification
int main(void)
{
    string serial = "";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Print the Tree in-order
    cout << endl;
    sln.print_inorder(root);
    cout << endl;

    serial = sln.serialize(root);
    if (serial == "1,2,3,#,#,4,5,#,#,#,#,") cout << "1. PASS" << endl;

    // Let's do the desrialize now
    TreeNode* newRoot = sln.deserialize(serial);

    // Print the Tree in-order
    cout << endl;
    sln.print_inorder(newRoot);
    cout << endl;

    return 0;
}

#endif // FORREF
