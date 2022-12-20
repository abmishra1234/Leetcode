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

#define _CRT_SECURE_NO_WARNINGS

/*
    Your code is not performant at all,
    check the serious issue with code,

    Use some caching approach in the given problem to resolve
    See the memoization beneficial here ?

    You are doing lot's work again and again without taking your mind??

*/

//#define FORREF
#ifndef FORREF
struct TrieNode {
    bool wc;
    TrieNode* ch[26];

    void create() {
        wc = false;
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
    }

}pool[150000];
int pid;

// {string type, {int type, bool type}}
typedef pair<string, int> psi;

// I wanted to cache this as a key for optimizing my recursive code 

struct MyHash {
    auto operator()(const psi& p)const {
        return hash<string>{}(p.first) ^ hash<int>{}(p.second);
    }
};

typedef unordered_map<psi, bool, MyHash> MyMap;
MyMap m;


// Trie class
class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        pid = 0;
        root = &pool[pid++];
        root->create();
    }
    void addWord(string word) {
        TrieNode* start = root;
        int wl = (int) word.length();
        for (int i = 0; i < wl;) {
            int code = word.at(i) - 'a';
            if (start->ch[code] == nullptr) {
                start->ch[code] = &pool[pid++];
                start->ch[code]->create();
            }
            start = start->ch[code];
            ++i;
            if (i == wl) {
                start->wc = true;
                break;
            }
        }
    }

    bool search(string word) {
        m.clear();
        return solve(root, word, 0);
    }

    bool solve(TrieNode* root, string word, int pos) {
        // so this is the base case where until this point you found the match
        if (pos >= word.length()) return root->wc;
        if (!root) return false;

        //if (m.find({ word, pos }) != m.end()) return m[{word, pos}];

        if (word[pos] != '.') {
            int code = word.at(pos) - 'a';
            if (root->ch[code] == nullptr) return false;
            root = root->ch[code];
            return solve(root, word, pos + 1);
        }

        bool result = false;
        for (int i = 0; i < 26; ++i) {
            if (root->ch[i]) {
                result |= solve(root->ch[i], word, pos + 1);
                if (result) return true;
            }
        }
        //m[{word, pos}] = result;

        return result;
    }
};

WordDictionary sln;

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main(void)
{
    // Define your custom test cases to verify the logic expected

    return 0;
}

#endif // FORREF