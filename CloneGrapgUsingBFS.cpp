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
//#define FORREF
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

/*
    What wend wrong in my first attempt, why it not delivered the expected result?
    Let's Think on it
    - Let's revise your bfs algorithm one's again
        -- I Just forget to revise or right steps on paper to go by algorithm
        -- For bfs kind of logic, dry run is very definite think to help you in getting right result.
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // if the passed graph is empty, than their clone is also empty
        // and return from here only
        Node* clone_node = nullptr;
        if (!node) return clone_node;

        unordered_map<Node*, Node*> mapped;
        list<Node*> q; // creating one queue here for managing bfs traversing order
        unordered_set<Node*> visited;

        // Let's create a map to hold the mapping from origional node and new node
        clone_node = new Node(node->val);
        mapped[node] = clone_node;
        q.push_back(node);
        visited.insert(node);

        while (q.empty() == false) {
            Node* tnode = q.front();
            q.pop_front();

            for (auto n : tnode->neighbors) {
                if (visited.find(n) == visited.end()) {
                    visited.insert(n);
                    mapped[n] = new Node(n->val);
                    q.push_back(n);
                }
                mapped[tnode]->neighbors.push_back(mapped[n]);
            }
        }

        return clone_node;
    }

    // method for traversing the bfs way
    vector<int> bfs_traverse(Node* node) {
        vector<int> result;

        // As you know your this problem have clearly
        // mentioned that you have unique value for all the node
        // for now just assuming that this bfs have max size queue of 10000 element
        vector<bool> visited(10002, false); // 100 X 100

        // This is a queue system for handling of bfs
        list<Node*>* lp = new list<Node*>();
        
        // Put your starting node into the queue to start
        lp->push_back(node);
        visited[node->val] = true;
        result.push_back(node->val);

        // iterate your queue
        while (lp->empty() == false) {
            Node* tnode = lp->front();
            lp->pop_front();
            
            for (auto n : tnode->neighbors) {
                if (visited[n->val] == false) {
                    visited[n->val] = true;
                    result.push_back(n->val);
                    lp->push_back(n);
                }
            }
        }
        
        for (auto elem : result) cout << elem << " ";
        cout << endl;

        return result;
    }
};

Solution sln;

int main() {
    // testing and verification method for your logic
    // this is the adjacency list of given graph
    vector<vector<int>> adjList = { {2,4},{1,3},{2,4},{1,3} };
    
    Node* node_1 = new Node(1);
    Node* node_2 = new Node(2);
    Node* node_3 = new Node(3);
    Node* node_4 = new Node(4);

    for (int i = 1; i <= 4; ++i) {
        if (i == 1) {
            node_1->neighbors.push_back(node_2);
            node_1->neighbors.push_back(node_4);
        }
        else if (i == 2) {
            node_2->neighbors.push_back(node_1);
            node_2->neighbors.push_back(node_3);
        }
        else if (i == 3) {
            node_3->neighbors.push_back(node_2);
            node_3->neighbors.push_back(node_4);
        }
        else if (i == 4) {
            node_4->neighbors.push_back(node_1);
            node_4->neighbors.push_back(node_3);
        }
    }

    // How do you test that your code is working fine?
    // So for testing purpose, you have to write one traversing method, 
    // and do the the traversing for both origional graph and clonned graph
    // verify with the result of traversing it??

    vector<int> result_orig;
    vector<int> result_clone;

    // there are two different ways to traverse the graph using bfs or dfs
    // Let's do the traversing by using bfs here and chek the result using two vector comparison???

    result_orig = sln.bfs_traverse(node_1);
    Node* clone_node = sln.cloneGraph(node_1);
    result_clone = sln.bfs_traverse(clone_node);

    bool failed = false;
    for (int i = 0; i < result_orig.size(); ++i) {
        if (result_clone[i] != result_orig[i]) {
            cout << "Failed the comparison!!" << endl;
            failed = true;
            break;
        }
    }

    //if (!failed) cout << "Pass the Test case!!!" << endl;

    return 0;
}

#endif // FORREF