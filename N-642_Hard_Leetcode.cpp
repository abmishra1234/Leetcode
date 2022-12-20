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

#define FORREF
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

typedef unordered_map<string, int> MyMap;
MyMap m;

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
    TrieNode* root;
    string search;
public:
    int getcode(char ch) {
        if (ch == ' ') return 26;
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
            auto it = start->hotword->find({ sentence, m[sentence] });
            if(it == start->hotword->end()) start->hotword->insert({ sentence ,hotness });
            else {
                int times = it->second;
                start->hotword->erase(it);
                start->hotword->insert({ sentence, times + hotness });
            }
        }
        m[sentence] += hotness;
    }
    void precompute(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
            m[sentences[i]] = times[i];
        }
    }

    vector<string> recommend(string prefix) {
        vector<string> result;
        TrieNode* start = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int code = getcode(prefix[i]);
            if (start->ch[code] == nullptr) {
                return {};
            }
            start = start->ch[code];
        }

        // so you reached the prefix leaf character/node
        int cnt = 3;
        auto it = start->hotword->begin();
        while (cnt > 0 && it != start->hotword->end()) {
            result.push_back(it->first);
            it++;
            --cnt;
        }
        return result;
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

        m.clear();
        // pre compute and populate your trie for given sentences and their hotness
        precompute(sentences, times);
        /*
            This string is empty by now and I am expecting the query string will get updated
            int the input method.
        */ 
        search = ""; 
    }

    vector<string> input(char c) {
        /*
            Here in this method, there are two path as per the problem
            Path 1 - termination of typing by putting the character '#'
            Path 2 - You are typing the character in their pattern to be recommended??

            So we have to handle these two path seperately with them to consider according to the problem
        */
            
        if (c == '#') {
            insert(search, 1);
            search = "";
            return {};
        }
        else
        {
            search += c;
            return recommend(search);
        }
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