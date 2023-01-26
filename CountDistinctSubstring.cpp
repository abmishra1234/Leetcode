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

class Node {
public:
    Node* childs[26];
    void create() {
        for (int i = 0; i < 26; ++i) childs[i] = nullptr;
    }
    bool contains(char ch) {
        return childs[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        return childs[ch - 'a'];
    }
    void put(char ch, Node* np) {
        np->create();
        childs[ch - 'a'] = np;
    }
}pool[200000];
int pind;

int countDistinctSubstrings(string s) {
    pind = 0;
    Node* root = &pool[pind++];
    root->create();
    int count = 0;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
        Node* start = root;
        for (int j = i; j < sz; ++j) {
            if (!start->contains(s[j])) {
                start->put(s[j], &pool[pind++]);
                ++count;
            }
            start = start->get(s[j]);
        }
    }
    return count + 1;
}

int main(void)
{

    return 0;
}

#endif // FORREF