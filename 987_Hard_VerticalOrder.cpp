// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=22

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

//#define FORREF
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
    /*
        Vertical Order Traversal of a Binary Tree
        There are two important point in your output here,
        1. level order, 2. inside the leavel, reading should be vertical
        from left to right

        Ex:01
        arr : [3,9,20,null,null, 15,7]
        output : [[9],[3,15], [20], [7]]

        it means that you should collect data in the form of
        column wise (L -> R) and rowwise (T -> B)

        so, it is giving me intuition that incase, you will
        able to collect the Nodes of binary tree in the form of

        map : col vs map1
        map1: row vs values

        @Alert: you might have duplicate value or multiple values at same row and col
        so choosing your right DS is improtant, and I can observe that multiset could be
        good choice for us because it should be sorted also required in the problem

    */

    typedef map<int, map<int, multiset<int>>> MyMap; // col, row, TreeNode*
    typedef pair<int, pair<int, TreeNode*>> p3i; // col, row, TreeNode*
    typedef deque<p3i> MyDeque;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // So in the problem it is given that, you should print the
        // nodes in the order of 
        // 1. Column (smallest to bigger)
        // 2. Row ( top to bottom )

        // @Info : root has col:0, row:0
        // map<int, map<int, multiset<int>>
        MyMap m;
        MyDeque q;

        // first push the root into the deque
        q.push_back({ 0,{0, root} });

        while (!q.empty()) {
            int qs = q.size();

            for (int i = 0; i < qs; ++i) {
                p3i p = q.front();
                q.pop_front();

                if (p.second.second->left) {
                    q.push_back({ p.first - 1, {p.second.first + 1, p.second.second->left} });
                }

                if (p.second.second->right) {
                    q.push_back({ p.first + 1, {p.second.first + 1, p.second.second->right} });
                }

                m[p.first][p.second.first].insert(p.second.second->val);
            }
        }

        // The Last step is to generate the final ans from the map
        vector<vector<int>> ans;
        auto it = m.begin();

        while (it != m.end()) {
            vector<int> v;
            auto cit = it->second.begin();
            while (cit != it->second.end()) {
                auto msit = cit->second.begin();
                while (msit != cit->second.end()) {
                    v.push_back(*msit);
                    ++msit;
                }
                ++cit;
            }
            ans.push_back(v);
            ++it;
        }
        return ans;
    }
};

// So result getting TLE, so let's debug the code now
Solution sln;

int main(void)
{
    TreeNode* root;

    // TC #1
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> ans = sln.verticalTraversal(root);

    return 0;
}

#endif // FORREF
