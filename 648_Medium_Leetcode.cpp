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
/*
    Replace words
    Algorithm for this problem solution,
    1. Create one Trie and put the all dictionary word inside this trie
    2. Parse the given sentence word by word and check does any root matching?
    3. The first root found will be the replacing root instead of word
    4. Continue this process until the sentence complete.

*/

struct TrieNode {
    bool wc;
    TrieNode* ch[26];
    void create() {
        wc = false;
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
    }
}pool[100000];
int pind = 0;


class Solution {
public:
    TrieNode* root;
    Solution() {
        pind = 0;
        root = &pool[pind++];
        root->create();
    }

    void insert(string word) {
        TrieNode* start = root;
        int i = 0;
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
    /*
        This below method is two step algorithm
        1. If you don't found any relevant prefix root than copy
        the complete word into the output sentence.
        2. 


    */
    void searchAndReplace(string sentence, string& changedSentenece) {
        
        bool skipuntil = false;
        TrieNode* start = root;
        int code;
        string rootword = "";


        for (int i = 0; i < sentence.length(); ++i) {
            if (skipuntil) {
                if (sentence[i] == ' ') skipuntil = false;
                continue;
            }
            
            code = sentence[i] - 'a';
            if (start->ch[code] == nullptr) {
                skipuntil = true;
                // copy the origional word of sentence in output sentence
                continue;
            }
            
            rootword += sentence[i];

            if (start->wc == true) {
                


            }








        }











    }


    string replaceWords(vector<string>& dictionary, 
        string sentence) {
        
        // add words inside the Trie DS
        for (auto s : dictionary) insert(s);

        string outstr = "";
        searchAndReplace(sentence, outstr);
        
        return outstr;
    }
};

Solution sln;

int main(void)
{
    vector<string> dict;
    string sentence;
    string outstr;

    // #tc 1
    dict = { "cat", "bat", "rat" };
    sentence = "the cattle was rattled by the battery";
    outstr = sln.replaceWords(dict, sentence);
    if (outstr == "the cat was rat by the bat") cout << "1. PASS" << endl;

    // #tc 2
    dict = { "a","b","c" };
    sentence = "aadsfasf absbs bbab cadsfafs";
    outstr = sln.replaceWords(dict, sentence);
    if (outstr == "a a b c") cout << "2. PASS" << endl;

    // #tc 3
    dict = { "ab","aba","abab" };
    sentence = "the ababwas ababy ab ababettery";
    outstr = sln.replaceWords(dict, sentence);
    if (outstr == "the ab ab ab ab") cout << "3. PASS" << endl;

    return 0;
}

#endif // FORREF