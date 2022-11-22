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

class ValidWordAbbr {
    // map for word and their abbreviated word
    unordered_map<string, unordered_set<string>> umap;

    // Create one utility private method to work inside the 
    // ValidWordAbbr class

    string doAbbredWord(string word) {
        size_t wl = word.length();
        /*
            if the word is empty
            or this word might be of length 1 or 2
        */
        if (wl <= 2)
            return word;
        
        // if wl > 2
        int remaiLength = wl - 2;
        string outStr = "";
        
        outStr += word.at(0);
        outStr += to_string(remaiLength);
        outStr += word.at(wl - 1);

        return outStr;
    }

public:

    ValidWordAbbr(vector<string>& dictionary) {
        // clear the map before proceeding further
        umap.clear(); 

        for (auto w : dictionary) {
            string abreWord = doAbbredWord(w);
            umap[abreWord].insert(w);
        }
    }

    bool isUnique(string word) {
        
        // There is no word in dictionary whose abbreviation is equal to word's abbreviation.
        bool cond_1 = false;
        bool cond_2 = false;

        // below code is for cond_1
        string abrword = doAbbredWord(word);
        auto it = umap.find(abrword);
        if (it == umap.end()) {
            cond_1 = true;
            return (cond_1 || cond_2);
        }

        // below code is for evaluating the second condition
        unordered_set<string> wordSet = it->second;
        int wset_size = wordSet.size();
        if (wset_size == 1 && strcmp(it->second.begin()->c_str(), word.c_str()) == 0) {
            cond_2 = true;
        }

        return (cond_1 || cond_2);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

int main()
{
    vector<string> dictionary = { "deer", "door", "cake", "card" };
    ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
    cout << "null" << endl;

    // 1.
    bool result = obj->isUnique("dear");
    cout << result << endl; // false

    result = obj->isUnique("cart");
    cout << result << endl; // true

    result = obj->isUnique("cane");
    cout << result << endl; // false

    result = obj->isUnique("make");
    cout << result << endl; // true  

    result = obj->isUnique("cake");
    cout << result << endl; // true  



	return 0;
}


#endif // FORREF



