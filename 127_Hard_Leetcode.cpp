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
class Solution {
    // Dict is just an efficient way t check the string exist in this set or not?
    // O(1) in best scenario
    typedef unordered_set<string> Dict;
    Dict d;

    typedef pair<string, int> psi;
    
    // This dequeue is primarily built for the handling of bfs implementation
    typedef deque<psi> MyQueue;
    MyQueue q;

public:

    Solution() {
    }

    void precache(vector<string>& wordList) {
        for (auto s : wordList) {
            d.insert(s);
        }
    }

    /*
        Here in problem, you have to find the minimum ladder length.
        So, my ideal concept here is to BFS, and so I have to prepare 
        the symbolic edge between word's for intermediate transformation.

        I am not sure about the recursion depth, so bfs is preferable here
    */

    void solve(string beginWord, string endWord, vector<string>& wordList, 
        string tempWord, int len, int &minLen) {
        
        // The First check in your code would be, does your endWord exist in Dict or not?
        if (d.find(endWord) == d.end()) {
            minLen = 0;
            return;
        }

        Dict visited; // for maintaining the visited

        minLen = INT_MAX;

        // So now move on to the first word
        q.push_back({ tempWord, 1 });
        visited.insert(tempWord);

        while (false  == q.empty()) {
            psi p = q.front();
            q.pop_front();

            if (p.first == endWord) {
                minLen = min(minLen, p.second);
                return;
            }

            for (int i = 0; i < p.first.length(); ++i) {
                for (int code = 'a'; code <= 'z'; ++code) {
                    if (code == p.first.at(i)) continue;
                    int temp = p.first[i];
                    p.first[i] = code;
                    // check does this exist in Dict or not?
                    if (visited.find(p.first) != visited.end()) {
                        p.first[i] = temp;
                        continue;
                    }

                    if (d.find(p.first) == d.end()) {
                        p.first[i] = temp;
                        continue;
                    }

                    visited.insert(p.first);
                    q.push_back({ p.first, p.second + 1 });
                    p.first[i] = temp;
                }
            }
        }
    }

    // Implementation completed, verification left
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // clean the slate
        d.clear();
        q.clear();

        precache(wordList); // this will fill the Dict
        int minLen = INT_MAX;
        solve(beginWord, endWord, wordList, beginWord, 0, minLen);
        return minLen == INT_MAX ? 0 : minLen;
    }
};

Solution sln;

int main(void)
{
    /*
        Let's write some verification code here to validate your implementation.
    */

    string beginWord;
    string endWord;
    vector<string> wordList;
    int ans;

    beginWord = "hit";
    endWord = "cog";
    wordList = { "hot","dot","dog","lot","log","cog" };
    ans = sln.ladderLength(beginWord, endWord, wordList);
    if (ans == 5) cout << "1. PASS" << endl;

    beginWord = "hit";
    endWord = "cog";
    wordList = { "hot","dot","dog","lot","log" };
    ans = sln.ladderLength(beginWord, endWord, wordList);
    if (ans == 0) cout << "2. PASS" << endl;


    return 0;
}

#endif // FORREF