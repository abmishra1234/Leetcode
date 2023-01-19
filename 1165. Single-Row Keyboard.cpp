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
    int calculateTime(string keyboard, string word) {
        vector<int> cache(26, 0);
        for (int i = 0; i < keyboard.length(); ++i) {
            int ind = keyboard.at(i) - 'a';
            cache[ind] = i;
        }
        int ans = 0;
        int curloc = 0;
        for (auto ch : word) {
            ans += abs(cache[ch - 'a'] - curloc);
            curloc = cache[ch - 'a'];
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF

