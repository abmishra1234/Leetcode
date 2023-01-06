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
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);

        // you have collected the all character frequency here
        for (auto ch : word) {
            int code = ch - 'a';
            freq[code] += 1;
        }
        
        // now try to change the frequency by 1 and check the frequency of rest char
        for (int i = 0; i < 26; ++i) { // outer loop
            if (freq[i] <= 0) continue;
            freq[i] -= 1;

            int fr = 0;
            bool failed = false;
            for (int j = 0; j < 26; ++j) {
                if (freq[j] == 0) continue;

                if (freq[j] != fr) {
                    if (fr == 0)
                        fr = freq[j];
                    else
                    {
                        failed = true;
                        break;
                    }
                }
            }
            if (!failed) return true;
            freq[i] += 1;

        }
        return false;
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