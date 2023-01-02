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

//#define FORREF
#ifndef FORREF
/*
    1. Take all words and push it into trie
    2. start bfs from all the nodes and check does we have any word
       available in trie DS?
    3. If you found any word completion that means you found one item of your
       answer
    4. One more optimization you can do here, you only need to start the finding word 
       whose first character start from the first character of word.
    
    So these are few cases to be considered while implementing solution of this problem
*/

#define MAXN 100005

class Trie {
public:
    class TrieNode {
    public:
        bool wc; // word complete
        TrieNode* ch[26];
        void create() {
            wc = false;
            for (int i = 0; i < 26; ++i) ch[i] = nullptr;
        }
    }pool[MAXN];
    int pind = 0;

    //--------------------------
    TrieNode* root;
    void init() {
        pind = 0;
        root = &pool[pind++];
        root->create();
    }
    
    // add
    void add(string word) {
        TrieNode* start = root;
        int i = 0;
        int code;
        for (; i < word.length();) {
            code = word.at(i) - 'a';
            if (!start->ch[code]) {
                start->ch[code] = &pool[pind++];
                start->ch[code]->create();
            }
            start = start->ch[code];
            ++i;
            if (i == word.length()) {
                start->wc = true;
                break;
            }
        }
    }

    // Solve method to be defined as custom search method to solve the problem
    void solve(vector<vector<char>>& board, vector<string>& words, vector<string> &ans) {
        TrieNode* start = root;

        // how to optimize your check here in this problem
        // As per my understing in this problem, I can see that, 


        




    }




};

class Solution {
public:
    Trie t;
    vector<string> findWords(vector<vector<char>>& board, 
        vector<string>& words) {
        // Trie based implementation
        t.init();
        vector<string> ans;
        t.solve(board, words, ans);
        return ans;
    }
};

Solution sln;

int main(void)
{
    // Write your verifcation code here below


    return 0;
}

#endif // FORREF