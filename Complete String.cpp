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

// https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
#define FORREF
#ifndef FORREF

vector<string> PrefixString(string s) {
    vector<string> ans;
    if (s.empty()) return {}; // empty prefix string
    int l = 0, r = 1;
    int sz = s.size();
    for (; r <= sz; ++r) {
        string tsrt = s.substr(l, r);
        cout << tsrt << endl;
        ans.push_back(tsrt);
        //ans.push_back(s.substr(l, r));
    }
    return ans;
}
/*
    Step 1 : Push the all string into tri data structure
    
    Step 2 : Iterate your all the strings and check does their all possible prefix
    string is already exist ? if so than that would be one of the key solution
    Your task here is to return the maximum length complete string
*/

// Build your Tri data structure
struct Node {
    Node* childs[26];
    bool eow;
    
    void init() {
        eow = false;
        for (int i = 0; i < 26; ++i) childs[i] = nullptr;
    }

    bool contain(char ch) {
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
    Trie() {
        init();
    }

    void init() {
        pind = 0;
        root = &pool[pind++];
        root->init();
    }

    // insert
    void insert(string word) {
        Node* start = root;
        int ws = word.size();

        for (int i = 0; i < ws; ++i) {
            if (!start->contain(word[i])) {
                start->put(word[i], &pool[pind++]);
            }
            start = start->get(word[i]);
        }
        start->eow = true;
    }

    bool search(string word) {
        Node* start = root;
        int ws = word.size();

        for (int i = 0; i < ws; ++i) {
            if (!start->contain(word[i])) {
                return false;
            }
            start = start->get(word[i]);
        }
        return start->eow == true;
    }
};

string completeString(int n, vector<string>& a) {
    Trie t;

    // step 1
    for (int i = 0; i < n; ++i)  t.insert(a[i]);

    // step 2
    string ans = "";
    int len = 0;

    for (string s : a) {
        // for prefix string check
        int i = 0; int j = 1; 
        string tstr = "";
        bool failed = false;
        for (; j <= s.size(); ++j) {
            tstr = s.substr(i, j);
            if (!t.search(tstr)) {
                failed = true;
                break;
            }
        }
        if (!failed) {
            if (s.size() >= len) {
                ans = s;
                len = s.size();
            }
        }
    }

    if (ans.empty()) ans = "None";

    return ans;
}


int main(void)
{
    PrefixString("ninja");

    return 0;
}

#endif // FORREF