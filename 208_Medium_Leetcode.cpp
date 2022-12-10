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

struct TrieNode {
    bool wc;
    TrieNode* ch[26];
    void create() {
        wc = false;
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
    }
}pool[100000];
int pind = 0;


class Trie {
    TrieNode* root;
public:
    Trie() {
        pind = 0;
        root = &pool[pind++];
        root->create();
    }

    void insert(string word) {
        TrieNode* start = root;
        int i=0;
        while (word[i] != '\0') {
            int code = word[i] - 'a';
            if (start->ch[code] == nullptr) {
                start->ch[code] = &pool[pind++];
                start->ch[code]->create();
            }
            start = start->ch[code];
            i++;
            if (word[i] == '\0') {
                start->wc = true;
                break;
            }
        }
    }

    bool search(string word) {
        TrieNode* start = root;
        int i = 0;
        while (word[i] != '\0') {
            int code = word[i] - 'a';
            if (start->ch[code] == nullptr) {
                return false;
            }
            start = start->ch[code];
            i++;
            if (word[i] == '\0') {
                break;
            }
        }
        return start->wc;
    }

    bool startsWith(string word) {
        TrieNode* start = root;
        int i = 0;
        while (word[i] != '\0') {
            int code = word[i] - 'a';
            if (start->ch[code] == nullptr) {
                return false;
            }
            start = start->ch[code];
            i++;
            if (word[i] == '\0') {
                break;
            }
        }
        return true;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF