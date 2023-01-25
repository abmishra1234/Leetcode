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
class Node {
public:
    Node* childs[26];
    int wf; // finished word count
    int wc; // this is prefix char freq

    void init() {
        wf = wc = 0;
        for (int i = 0; i < 26; ++i) childs[i] = nullptr;
    }

    bool contains(char ch) {
        return childs[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return childs[ch - 'a'];
    }

    void put(char ch, Node* np) {
        np->init();
        childs[ch - 'a'] = np;
    }

    void incWordCnt() {
        wf++;
    }
    void decWordCnr() {
        wf--;
    }

    void incPrefCnt() {
        wc++;
    }
    void decPrefCnr() {
        wc--;
    }
    /*
        int wf; // finished word count
        int wc; // this is prefix char freq
    */
    int getWordCnt() {
        return wf;
    }
    int getPrefCnt() {
        return wc;
    }
};// pool[200000];
//int pind;

class Trie {
    Node* root;
public:

    Trie() {
        //pind = 0;
        //root = &pool[pind++];
        root = new Node();
        root->init();
    }

    void insert(string& word) {
        Node* start = root;
        int ws = word.size();
        for (int i = 0; i < ws; ++i) {
            if (!start->contains(word[i])) {
                start->put(word[i], new Node()/*&pool[pind++]*/);
            }
            start = start->get(word[i]);
            start->incPrefCnt();
        }
        start->incWordCnt();
    }

    int countWordsEqualTo(string& word) {
        Node* start = root;
        int ws = word.size();
        for (int i = 0; i < ws; ++i) {
            if (!start->contains(word[i])) {
                return 0;
            }
            start = start->get(word[i]);
        }
        return start->getWordCnt();
    }

    int countWordsStartingWith(string& word) {
        Node* start = root;
        int ws = word.size();
        for (int i = 0; i < ws; ++i) {
            if (!start->contains(word[i])) {
                return 0;
            }
            start = start->get(word[i]);
        }
        return start->getPrefCnt();
    }

    /*
        This impl is correct only if
        it is make sure that erase is always 
        called with existing word in Trie.
    */
    void erase(string& word) {
        Node* start = root;
        int ws = word.size();
        for (int i = 0; i < ws; ++i) {
            if (start->contains(word[i])) {
                start = start->get(word[i]);
                start->decPrefCnr();
            }
            else
                return;
        }
        start->decWordCnr();
    }
};

/*
2
7
insert apple
insert mango
insert banana
insert apple
countWordsEqualTo banana
countWordsStartingWith app
erase banana
5
insert abc
insert aef
countWordsEqualTo abc
countWordsStartingWith a

*/


int main(void)
{
    Trie t;
    string str = "abc";
    t.insert(str);
    t.insert(str);
    str = "aef";
    t.insert(str);

    str = "abc";
    int ans = t.countWordsEqualTo(str);
    cout << ans << endl;

    str = "a";
    ans = t.countWordsStartingWith(str);
    cout << ans << endl;


    return 0;
}

#endif // FORREF