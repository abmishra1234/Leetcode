// https://www.youtube.com/watch?v=ZbybYvcVLks
// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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

/*
    The maximum width of a tree is the maximum width among all levels.

    The width of one level is defined as the length between the end-nodes 
    (the leftmost and rightmost non-null nodes), where the null nodes between 
    the end-nodes that would be present in a complete binary tree 
    extending down to that level are also counted 
    into the length calculation.

    It is guaranteed that the answer will in the range of a 
    32-bit signed integer.

    One quick intution , i am getting here that this is based on level order
    traversing only.

*/

class Solution {
    typedef pair<TreeNode*, long long> MyPair;
public:
    int widthOfBinaryTree(TreeNode* root) {
        // the logic is simple here, the first thing you have
        // to do to check the root. As per problem constraint,
        // this check might not required ??
        if (!root) return 0;
        // second step is to push the root into the queue
        // you need the Node and some index to attached with every node 
        // in your tree symbolically for all nodes ( nullptr or not nullptr both)
        deque<MyPair> q;
        long long index = 1;
        q.push_back({ root, index });
        // define the data strucure to hold the level order data
        vector<vector<int>> ldata;
        
        int maxwidth = INT_MIN;

        while (!q.empty()) {
            int qs = (int) q.size();
            vector<int> v;
            int curmin = (int) q.front().second;
            int lmin = 0, lmax = 0;
            for (int i = 0; i < qs; ++i) {
                TreeNode* np = q.front().first;
                long long cur_ind = q.front().second - curmin;
                q.pop_front();

                if (i == 0) lmin = cur_ind;
                if (i == (qs - 1)) lmax = cur_ind;

                if (np->left) {
                    q.push_back({ np->left, 2*cur_ind });
                }

                if (np->right) {
                    q.push_back({ np->right,1+ (2 * cur_ind) });
                }
            }
            maxwidth = max(maxwidth, (int)(lmax - lmin + 1));
        }

        return maxwidth;
    }
};


int main(void)
{
    return 0;
}

#endif // FORREF