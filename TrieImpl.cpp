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
    bool wc;

    void init() {
        wc = false;
        for (int i = 0; i < 26; ++i) childs[i] = nullptr;
    }

    bool contains(char ch) {
        return childs[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return childs[ch - 'a'];
    }

    void put(char ch, Node* np) {
        np->init();
        childs[ch - 'a'] = np;
    }
}pool[200000];
int pind;

class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        pind = 0;
        root = &pool[pind++];
        root->init();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* start = root;
        int ws = word.size();
        for (int i = 0; i < ws; ++i) {
            if (!start->contains(word[i])) {
                start->put(word[i], &pool[pind++]);
            }
            start = start->get(word[i]);
            if (i == (ws - 1)) {
                start->wc = true;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* start = root;
        int ws = word.size();
        for (int i = 0; i < ws; ++i) {
            if (!start->contains(word[i])) {
                return false;
            }
            start = start->get(word[i]);
        }
        return start->wc;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* start = root;
        int ws = prefix.size();
        for (int i = 0; i < ws; ++i) {
            if (!start->contains(prefix[i])) {
                return false;
            }
            start = start->get(prefix[i]);
        }

        return (start != nullptr);
    }
};

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
int main(void)
{

    return 0;
}

#endif // FORREF