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

// Not completed Yet...

#define FORREF
#ifndef FORREF
/*
    Implementing the LFU & MFU together
    
    R.1 -> 
    You have to build a class for maintaining the string 
    in such a way that, you will able to look the string
    fast enough like O(1) time complexity

    inc(string key), dec(string key) these both will be 
    fulfilled with this fast lookup algorithm

    So, it is giving me intuition that unordered_map<string, ?> 
    may work for us in this requirement

    Until this point this is ok.

    Now another two api which is finading max and min freqency
    value string from your cache, might be little 
    challenging so let's what intuition you are getting

    If you imagine this, you will realized that, something 
    kind of count sort data structure might be useful here
    to achieve the api requirement









*/


//--------------------

class AllOne {
public:


    AllOne() {

    }

    void inc(string key) {

    }

    void dec(string key) {

    }

    string getMaxKey() {
        return "";
    }

    string getMinKey() {
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */



//--------------------
typedef pair<string, int> psi;

int main(void)
{


    return 0;
}

#endif // FORREF