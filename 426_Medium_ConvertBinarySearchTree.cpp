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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    
    /*
        THis is your pre step in which we are 
        just writing the in-order traversing for BST
    */
    void solve(Node* root, deque<Node*> &list) {
        if (!root) return;
        solve(root->left, list);
        list.push_back(root);
        solve(root->right, list);
    }
    
    /*
        Two step algorithm, required to be implemented here
        
        Pre Step?
        one Pre step of this problem is to write the inorder traversing for the given BST

        Step 01: Try to build the sorted doublt linked list backed with start and end pointer.
        I mean to say here, while building the Doubly Linklist, build the head and tail pointer
        also which will be helpful in reaching the step 02 process.

        Step 02: You know the first and last node so only task is to connect them to make
        Circular Linkedlist

    */
    Node* treeToDoublyList(Node* root) {
        deque<Node*> q;
        solve(root, q);

        Node* head = nullptr, * tail = nullptr;

        while (false == q.empty()) {
            Node* temp = q.front();
            q.pop_front();
            if (!head) {
                head = tail = temp;
            }
            else {
                tail->right = temp;
                temp->left = tail;
                tail = tail->right;
            }
        }
        if(head)
            head->left = tail;
        if(tail)
            tail->right = head;

        return head;
    }
};

Solution sln;

int main(void)
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    sln.treeToDoublyList(root);

    return 0;
}

#endif // FORREF