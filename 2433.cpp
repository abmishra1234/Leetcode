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
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for (auto ch : word) {
            freq[ch - 'a'] += 1;
        }

        // freq > 1 count??
        int maxv = INT_MIN;
        int id = -1;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0 && freq[i] > maxv)
            {
                maxv = freq[i];
                id = i;
            }
        }

        freq[id] -= 1;

        unordered_set<int> s;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                s.insert(freq[i]);
            }
        }
        return (s.size() == 1);
    }
};

Solution sln;

int main(void)
{
    string word;
    bool ans;
    
    word = "abbcc";
    ans = sln.equalFrequency(word);
    if (ans == true) cout << "1. PASS" << endl;

    word = "cccaa";
    ans = sln.equalFrequency(word);
    if (ans == true) cout << "2. PASS" << endl;



    return 0;
}

#endif // FORREF