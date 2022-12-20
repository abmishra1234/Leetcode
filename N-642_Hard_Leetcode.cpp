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

//#define FORREF
#ifndef FORREF

#define MAXT 100000

typedef pair<string, int> psi;
struct Cmp {
    bool operator()(const psi& a, const psi& b) const {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

typedef set<psi, Cmp> MyCustomSet;


struct TrieNode {
    MyCustomSet* hotword; // This is suppose to hold the hot word list, max would be 03
    TrieNode* ch[27]; // 26 alphabets and one space character
    void create() {
        hotword = nullptr;
        for (int i = 0; i < 27; ++i) ch[i] = nullptr;
    }
}pool[MAXT];
int pind;


class AutocompleteSystem {
#define SPACE ' '
    TrieNode* root;
public:
    int getcode(char ch) {
        if (ch == ' ') return SPACE;
        return ch - 'a'; // otherwise all small case value returned
    }
    
    // insert into the trie methos
    void insert(string sentence, int hotness) {
        TrieNode* start = root;
        for (int i = 0; i < sentence.length(); ++i) {
            int code = getcode(sentence[i]);
            if (start->ch[code] == nullptr) {
                start->ch[code] = &pool[pind++];
                start->ch[code]->create();
            }
            start = start->ch[code];
            // Assign the sorted set pointer with the given constarint.
            // constraint rules are like below
            if (start->hotword == nullptr) {
                start->hotword = new MyCustomSet();
            }
            // Let's see if you need some improvement in logic here?
            // One optimization in memory usage here instead of putting eveything here
            // only put the id value and put the element in some db
            start->hotword->insert({ sentence ,hotness });
        }
    }

    void precompute(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }

    /*
        This method is for making something which is pre computed or cleaned the canvas, and
        so on so forth...
    */
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        // For Trie DS init step
        pind = 0;
        root = &pool[pind++];
        root->create();

        // pre compute and populate your trie for given sentences and their hotness
        precompute(sentences, times);
    }

    vector<string> input(char c) {
        


    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

int main(void)
{
    //cout << (int)SPACE << endl;




    return 0;
}

#endif // FORREF