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
/*
    @Note: This problem could be solved by using Trie approach 
*/
#ifndef FORREF
class Node {
public:
    Node* childs[26];
    Node() {
        for (int i = 0; i < 26; ++i) childs[i] = nullptr;
    }
    bool contains(char ch) {
        return childs[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        return childs[ch - 'a'];
    }
    void put(char ch, Node* np) {
        childs[ch - 'a'] = np;
    }
};

class Solution {
public:
    int countDistinct(string s) {
        Node* root = new Node();
        int count = 0;
        int sz = s.size();
        for (int i = 0; i < ns; ++i) {
            Node* start = root;
            for (int j = i; j < ns; ++j) {
                if (!start->contains(s[j])) {
                    start->put(s[j], new Node());
                    ++count;
                }
                start = start->get(s[j]);
            }
        }
        return count;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF