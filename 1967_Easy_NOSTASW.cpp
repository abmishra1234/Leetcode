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

struct Node {
    Node* childs[26];
    bool eow;
    void init() {
        eow = false;
        for (int i = 0; i < 26; ++i) childs[i] = nullptr;
    }
    bool contain(char ch) {
        return (childs[ch - 'a'] != nullptr);
    }
    Node* get(char ch) {
        return childs[ch - 'a'];
    }
    void put(char ch, Node* np) {
        np->init();
        childs[ch - 'a'] = np;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->init();
    }

    void insertword(string& word) {
        Node* start = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!start->contain(word[i])) {
                start->put(word[i], new Node());
            }
            start = start->get(word[i]);
        }
        start->eow = true;
    }
    
    bool search(string& word) {
        Node* start = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!start->contain(word[i])) {
                return false;
            }
            start = start->get(word[i]);
        }
        return start->eow;
    }
};

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        Trie t;
        int wl = word.length();
        int i = 0;
        while (i < wl) {
            for (int j = 1; j <= wl-i; ++j) {
                // @Learning --- j is count of character in below api
                string s = word.substr(i, j);
                t.insertword(s);
            }
            ++i;
        }

        int count = 0;
        for (auto s : patterns) {
            if (t.search(s)) ++count;
        }
        return count;
    }
};

Solution sln;

int main(void)
{
    vector<string> pattern;
    string word;

    pattern = { "dgvyb","j","rc","b","gve","rkbzd","i","ial","tws","c","z" };
    word = "zcobp";

    int ans = sln.numOfStrings(pattern, word);

    return 0;
}

#endif // FORREF