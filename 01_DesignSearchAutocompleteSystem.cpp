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

// Approach 01
//#define FORREF
#ifndef FORREF
typedef pair<string, int> psi;
vector<psi> worddb;
int db_ind;

struct MyCmp {
    bool operator()(const int i, const int j) const {
        if (worddb[i].second == worddb[j].second) {
            // using std string class < oprator
            // @Note , I hope this won't have any issue...
            return worddb[i].first.compare(worddb[j].first) < 0;
        }
        return worddb[i].second > worddb[j].second;
    }
};

typedef set<int, MyCmp> MySet;
unordered_map<string, int> m;

int getcode(char ch) {
    if (ch == ' ') return 26;
    return ch - 'a';
}

struct TrieNode {
    bool wc;
    TrieNode* ch[27];
    // this is to be considered as Set on tip of prefix
    // It will hold the recommendation word at the tip of prefix
    MySet* pSet;  // 04 byte
    void create() {
        wc = false;
        pSet = new MySet();
        for (int i = 0; i < 27; ++i) ch[i] = nullptr;
    }
}pool[100000];
int pind = 0;

//----------------------------------------

class AutocompleteSystem {
    TrieNode* root;

    void insert(string word, int pool_ind) {
        TrieNode* start = root;
        int i = 0;
        while (word[i] != '\0') {
            int code = getcode(word[i]);
            if (start->ch[code] == nullptr) {
                start->ch[code] = &pool[pind];
                start->ch[code]->create();
                ++pind;
            }
            i++;
            start = start->ch[code];
            start->pSet->insert(pool_ind);
            if (word[i] == '\0') {
                start->wc = true;
                break;
            }
        }
    }

    vector<string> search(string word) {
        vector<string> out;
        TrieNode* start = root;
        int i = 0;
        while (word[i] != '\0') {
            int code = getcode(word[i]);
            if (start->ch[code] == nullptr) {
                return {};
            }
            start = start->ch[code];
            i++;
            if (word[i] == '\0') {
                // populate your out here
                int K = 3;
                auto it = start->pSet->begin();
                while (K > 0 && it != start->pSet->end()) {
                    out.push_back(worddb[*it].first);
                    K--, it++;
                }
                break;
            }
        }
        return out;
    }
    
    string prefixword;

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        // for root to initialised
        pind = 0;
        root = &pool[pind++];
        root->create();

        m.clear();
        worddb.clear();
        worddb.resize(100000);
        db_ind = 0;
        for (auto i = 0; i < sentences.size(); ++i) {
            worddb[i] = { sentences[i], times[i] };
            m[sentences[i]] = i;
            insert(sentences[i], i);
            db_ind++;
        }
        prefixword = "";
    }

    vector<string> input(char c) {
        vector<string> result;
        if (c == '#') {
            /*
                How you will handle the repetation of sentence in the dictionary.
                for that purpose we should create the one map of string vs cnt to maintain the
            */

            auto it = m.find(prefixword);
            if (it == m.end()) {
                worddb[db_ind] = { prefixword, 1 };
                m[prefixword] = db_ind;
            }
            else worddb[it->second].second++;
            insert(prefixword, db_ind);
            prefixword = "";
            result = {};
        }
        else {
            prefixword += c;
            result = search(prefixword);
        }
        return result;
    }
};

int main(void)
{
    // write some verification code first
    vector<string> sentence;
    vector<int> times;
    char ch;
    vector<string> output;

    sentence = { "i love you", "island", "ironman", "i love leetcode" };
    times = { 5, 3, 2, 2 };

    AutocompleteSystem sln(sentence, times);
    // #tc 1
    ch = 'i';

    output = sln.input(ch);
    if (output.size() == 3) {
        if (output[0] == "i love you"
            && output[1] == "island" && output[2] == "i love leetcode") 
            cout << "1. PASS" << endl;
    }

    // #tc 2
    ch = ' ';

    output = sln.input(ch);
    if (output.size() == 2) {
        if (output[0] == "i love you"
            && output[1] == "i love leetcode")
            cout << "2. PASS" << endl;
    }

    // #tc 3
    ch = 'a';

    output = sln.input(ch);
    if (output.size() == 0) {
       cout << "3. PASS" << endl;
    }

    ch = '#';
    output = sln.input(ch);
    // Exit with empty recommendation

    return 0;
}

#endif // FORREF