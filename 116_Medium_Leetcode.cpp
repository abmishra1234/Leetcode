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

//#define FORREF
#ifndef FORREF

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#define MAXN 4100

typedef pair<Node*, int> ppi; // <Node* , level>
queue<ppi> q;

class Solution {
    Node* root;

public:
    /*
        Let's modify your level order code for maintaining the 
        level by level of the tree node
    */
    Node* levelorder(Node* root, vector<vector<Node*>> &leveldata) {
        if (!root) return nullptr;

        // the first thing you should do to clean the queue
        while (q.empty() == false) q.pop();

        int level = 1;
        // push the starting node into the queue
        q.push({ root, level });
        leveldata[level].push_back(root);

        cout << endl;
        while (q.empty() == false) {
            ppi p = q.front();
            // Just to get the updated level below 
            level = p.second;
            q.pop();

            cout << "val = " << p.first->val
                << ", level = " << p.second << endl;

            if (p.first->left) {
                q.push({ p.first->left, p.second + 1 });
                leveldata[p.second + 1].push_back(p.first->left);
            }

            if (p.first->right) {
                q.push({ p.first->right, p.second + 1 });
                leveldata[p.second + 1].push_back(p.first->right);
            }
        }
        
        // now you have level data, it's time to set next pointer
        // connection properly

        for (int i = 1; i <= level; ++i) {
            while (leveldata[i].size() >= 1) {
                if (leveldata[i].size() == 1) {
                    leveldata[i][0]->next = nullptr;
                    leveldata[i].erase(leveldata[i].begin());
                }
                else if (leveldata[i].size() > 1) {
                    leveldata[i][0]->next = leveldata[i][1];
                    leveldata[i].erase(leveldata[i].begin());
                }
            }
        }
        return root;
    }

    // Let's write logic for traversing the 
    // level order in binary tree
    Node* connect(Node* root) {
        if (!root) return root;
        vector<vector<Node*>> leveldata(MAXN, vector<Node*>());
        return levelorder(root, leveldata);
    }
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    Node* buildtree_util(const vector<int>& v, int index, Node* root) {
        if (index >= v.size()) return nullptr;
        
        // create root node
        root = new Node(v[index]);

        // build left child
        root->left = buildtree_util(v, 2*index+1, root->left);

        // build right child
        root->right = buildtree_util(v, 2*index+2, root->right);
        
        return root;
    }
    void buildtree(const vector<int> &v) {
        root = buildtree_util(v, 0, root);
        inorder(root);
        // Just clear the vector if anything already exist
        connect(root);
    }
};

Solution sln;


int main(void)
{
    vector<int> v = { 1,2,3,4,5,6,7 };
    sln.buildtree(v);

    return 0;
}

#endif // FORREF