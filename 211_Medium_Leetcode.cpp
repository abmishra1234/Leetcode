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
    There is something wrong in my approach it is almost in pathetic time complexity
    Let's Improve again
*/

#define FORREF
#ifndef FORREF
struct TrieNode {
    bool wc;
    TrieNode* ch[26];

    void create() {
        wc = false;
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
    }

}pool[100000];
int pid;


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
        int wl = word.length();
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
    /*
        if there is no dot in search str than search will be normal search in trie
        else, you have to follow the below role
        if '.' means it matches with any character so you have to use the 
        dfs kind of approach to validate the latter search.
    */
    bool search(string word) {
        return solve(root, word, 0);
    }

    bool solve(TrieNode* root, string word, int pos) {
        // so this is the base case where until this point you found the match
        if (pos >= word.length()) return word[pos-1] == '.' ? true : root->wc;
        if (!root) return false;
        if (word[pos] != '.') {
            int code = word.at(pos) - 'a';
            if (root->ch[code] == nullptr) return false;
            root = root->ch[code];
            return solve(root, word, pos + 1);
        }

        bool result = false;
        for (int i = 0; i < 26; ++i) {
            if (root->ch[i]) {
                result = solve(root->ch[i], word, pos + 1);
                if (!result) return false;
            }
        }
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