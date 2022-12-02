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

/*
    Constraints:
    The number of nodes in the graph is in the range [0, 100].
    1 <= Node.val <= 100
    Node.val is unique for each node.
    There are no repeated edges and no self-loops in the graph.
    The Graph is connected and all nodes can be visited starting from the given node.
*/
#define FORREF
#ifndef FORREF
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
protected:
    Node* clone_util(Node* node, unordered_map<int, Node*>& visited) {
        Node *tNode = new Node(node->val);
        visited[node->val] = tNode;

        for (auto n : node->neighbors) {
            auto it = visited.find(n->val);
            if (it == visited.end()) {
                // not present into the visited 
                Node* cn = clone_util(n, visited);
                tNode->neighbors.push_back(cn);
            }
            else tNode->neighbors.push_back(it->second); // I was doing one mistake here and my code was failing
        }
        return tNode;
    }
public:
    Node* cloneGraph(Node* node) {
        /*
            your code need create the clone of this graph
             There are two different approach is possible for handling this coding challenge
             1. Using DFS  and other is 
             2. using BFS
             for the below case let's do this with DFS Approach???
        
            At this point of time you are not clear with the number of nodes given and also
            this is something to manage the mapping and fast search, so let's consider 
            unordered_map<int, Node*> ( value and their corresponding new node ( Node*)
        */
        if (!node) return nullptr;
        unordered_map<int, Node*> visited;
        return clone_util(node, visited);
    }
};


Solution sln;

int main() {
    // testing and verification method for your logic


    return 0;
}

#endif // FORREF