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

/*
    Incomplete yet...
    Solution is Trie and dfs and backtrace
    Using bfs is confusing here so avoid this and try solution again...

*/



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

#define MAXN 200000
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

    // {row, col, string, TrieNode*}
    typedef pair<int, pair<int, pair<string, TrieNode*>>> p2ist; 

    bool isvalid(int x, int y, int R, int C) {
        if (x < 0 || x >= R) return false;
        if (y < 0 || y >= C) return false;
        return true;
    }

    /*
        Custom bfs for finding all the words starting from the perticular possible cell
    */
    void bfs(vector<vector<char>>& board, int R, int C, p2ist cell, unordered_set<string> &ans) {
        // so to avoid the cycle, use the visited[][] here
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        deque<p2ist> q;

        // push the first cell
        visited[cell.first][cell.second.first] = true;
        cell.second.second.first = cell.second.second.first + board[cell.first][cell.second.first];
        cell.second.second.second
            = cell.second.second.second->ch[board[cell.first][cell.second.first] - 'a'];
        q.push_back(cell);

        int code;

        // Iterate these 
        while (false == q.empty()) {
            p2ist p = q.front();
            q.pop_front();

            int x = p.first, y = p.second.first;
            string s = p.second.second.first;
            TrieNode* start = p.second.second.second;
            if (start->wc) ans.insert(s);

            // left
            y--;
            if (isvalid(x, y, R, C)
                && !visited[x][y]) {
                // does this new cell is part of trie word?
                code = board[x][y] - 'a';
                if (start->ch[code]) {
                    visited[x][y] = true;
                    q.push_back({ x,{y,{s + board[x][y], start->ch[code]}} });
                }
                //visited[x][y] = false;
            }
            ++y;

            // top
            x--;
            if (isvalid(x, y, R, C)
                && !visited[x][y]) {
                // does this new cell is part of trie word?
                code = board[x][y] - 'a';
                if (start->ch[code]) {
                    visited[x][y] = true;
                    q.push_back({ x,{y,{s + board[x][y], start->ch[code]}} });
                }
                //visited[x][y] = false;
            }
            ++x;

            // right
            y++;
            if (isvalid(x, y, R, C)
                && !visited[x][y]) {
                // does this new cell is part of trie word?
                code = board[x][y] - 'a';
                if (start->ch[code]) {
                    visited[x][y] = true;
                    q.push_back({ x,{y,{s + board[x][y], start->ch[code]}} });
                }
                //visited[x][y] = false;
            }
            --y;

            // bottom
            x++;
            if (isvalid(x, y, R, C)
                && !visited[x][y]) {
                // does this new cell is part of trie word?
                code = board[x][y] - 'a';
                if (start->ch[code]) {
                    visited[x][y] = true;
                    q.push_back({ x,{y,{s + board[x][y], start->ch[code]}} });
                }
                //visited[x][y] = false;
            }

            --x;
        }
    }

    // Solve method to be defined as custom search method to solve the problem
    void solve(vector<vector<char>>& board, vector<string>& words, 
        unordered_set<string> &ans) {

        // I am assuming that all the words are not empty
        set<char> chset;
        for (auto s : words) {
            chset.insert(s.at(0));
            add(s);
        }
        
        // Let's iterate the grid and start your bfs
        // here bfs edge is to be decided based on path exist in trie words
        int R = (int) board.size();
        int C = (int) board[0].size();

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // your element must be the part of chset
                if (chset.find(board[i][j]) == chset.end()) continue;
                bfs(board, R, C, { i,{ j,{"",root}}}, ans);
            }
        }
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
        unordered_set<string> wset;
        t.solve(board, words, wset);
        auto it = wset.begin();
        while (it != wset.end()) {
            ans.push_back(*it);
            ++it;
        }
        return ans;
    }
};

Solution sln;

/*
    TBD - This problem is failing for below test case
    Do the debug and solve the problem.
*/

int main(void)
{
    // Write your verifcation code here below
    vector<vector<char>> board = { {'o','a','a','n'},
        {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'} };

    vector<string> words = { "oath","pea","eat","rain","hklf", "hf" };
    vector<string> ans = sln.findWords(board, words);

    return 0;
}

#endif // FORREF