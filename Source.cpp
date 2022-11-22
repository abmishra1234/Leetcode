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

class RandomizedSet {
    // Array of integer
    vector<int> varr;
    
    // Map for value to array index
    unordered_map<int, int> umap; 

public:
    RandomizedSet() {
        umap.clear();
    }

    bool insert(int val) {
        auto it = umap.find(val);
        if (it != umap.end())
            return false;
        umap[val] = varr.size();
        varr.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = umap.find(val);
        if (it == umap.end())
            return false;

        // move ind element at last
        varr[it->second] = varr[varr.size() - 1];
        varr.pop_back();
        return true;
    }

    int getRandom() {
        return varr[rand() % varr.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */






int main()
{
	cout << "Hello !!" << endl;




	return 0;
}











#endif // FORREF



