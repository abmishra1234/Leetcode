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
    These are some standard tips and Tricks you should think??
    - This problem is good exercise of using the Trie and Priority Queue
      togethr 
    - Check all the optimisation of caching?
    - Try to think, multiple approach and see the comparison?
    - In Tire, node creation should be backed with Node Pool concept,
      also check the sanity of your approach with the tweek

    - Until you are not deleting any thing from the Trie or your solution
      you are safe to use caching heavily, it will optimize your time complexity

      incase you have delete api to implement than you should check that does
      your caching is helping you or not?
*/

#define FORREF
#ifndef FORREF
#define MAXP 100000
#define MAXCH 27
#define SPACE 26

typedef pair<string, int> psi; // pair of sentence vs freq count

struct Cmp {
    auto operator()(const psi& a, const psi& b) const {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

typedef set<psi, Cmp> MySet;

int getcode(char ch) {
    if (ch == ' ') return SPACE;
    return (ch - 'a');
}

struct TrieNode {
    MySet* sp;
    TrieNode* ch[27];

    void create() {
        sp = nullptr;
        for (int i = 0; i < MAXCH; ++i) ch[i] = nullptr;
    }
}pool[MAXP];
int pid;

typedef unordered_map<string, int> MyMap;
MyMap mp;

class AutocompleteSystem {
    string search;
    TrieNode* root;
public:

    void add(string sentence, int freq) {
        TrieNode* start = root;
        int code;
        for (int i = 0; i < sentence.length(); ) {
            code = getcode(sentence.at(i));
            
            if (root->ch[code] == nullptr) {
                root->ch[code] = &pool[pid++];
                root->ch[code]->create();
            }

            root = root->ch[code];
            if (root->sp == nullptr) {
                root->sp = new MySet();
                root->sp->insert({ sentence, freq });
            }
            else
            {
                root->sp->erase({ sentence, freq-1 });
                root->sp->insert({ sentence, freq });
            }
            ++i;
        }
    }

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        pid = 0;
        search = "";
        mp.clear();
        root = &pool[pid++];
        root->create();

        // Now you push the element into the trie
        for (int i = 0; i < sentences.size(); ++i) {
            add(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        vector<string> result;

        if (c == '#') {
            mp[search]++;
            add(search, mp[search]);
            search = "";
            return {};
        }
        else
        {
            search += c;
            // TBD, Write your search logic and return result from here
            

        }
        return result;
    }
};

/*
    Your TC are not strong enough, please build some of your own TC
    to verify your logic and complete it.
    This is your learning, to get the right motivation over the quick coding 
*/
int main(void)
{
    // write test case to cover your implementation


    return 0;
}

#endif // FORREF