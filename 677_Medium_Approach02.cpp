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

#define FORREF
#ifndef FORREF
// Approach 02 : Using Trie DS
struct TrieNode {
    bool kc; 
    int val;
    TrieNode* ch[26];

    void create() {
        kc = 0;
        val = 0;
        for (auto i = 0; i < 26; ++i) ch[i] = nullptr;
    }
}pool[100000];
int pind = 0;


class MapSum {
    TrieNode* root;
public:
    MapSum() {
        pind = 0;
        root = &pool[pind++];
        root->create();
    }

    void insert(string key, int val) {
        TrieNode* start = root;
        int i = 0;
        while (key[i] != '\0') {
            int code = key[i] - 'a';
            if (start->ch[code] == nullptr) {
                start->ch[code] = &pool[pind++];
                start->ch[code]->create();
            }
            start = start->ch[code];
            i++;
            if (key[i] == '\0') {
                start->kc = true;
                start->val = val;
                break;
            }
        }
    }

    // Write one utility method for calculating the sum for all the subsequent tree
    // for the prefix match
    void accumulate(TrieNode* root, int& final) {
        if (!root) return;
        if (root->kc) {
            // don't return from here since other deepdive word also have value
            final += root->val; 
        }

        for (int i = 0; i < 26; ++i) {
            if (root->ch[i])
                accumulate(root->ch[i], final);
        }
    }

    int sum(string word) {
        TrieNode* start = root;
        int i = 0;
        while (word[i] != '\0') {
            int code = word[i] - 'a';
            if (start->ch[code] == nullptr) {
                return 0;
            }
            start = start->ch[code];
            i++;
            if (word[i] == '\0') {
                break;
            }
        }
        int result = 0;
        accumulate(start, result);
        return result;
    }
};

int main(void)
{
    // Put some testing code to check the logic of your code
    MapSum* mp = new MapSum();
    int ans = 0;
    mp->insert("apple", 3);
    ans = mp->sum("ap");
    if (ans == 3) cout << "1. PASS" << endl;
    mp->insert("app", 2);
    ans = mp->sum("ap");



    return 0;
}

#endif // FORREF