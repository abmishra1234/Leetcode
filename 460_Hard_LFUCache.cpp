// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/

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
/*
    Performance requirement : 
    The functions get and put must each run in O(1) average time complexity.

    Design and implement a data structure for a Least Frequently Used (LFU) cache.
    
    Implement the LFUCache class:
    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    
    int get(int key) Gets the value of the key if the key exists in the cache. 
    Otherwise, returns -1.

    Approach:
    List, Sorted set and Unordered_map
*/

class LFUCache {
    typedef pair<int, pair<int, pair<int, int>>> p4i; // {key, {value, {freq, ts}}} 
    typedef pair<int, pair<int, int>> p3i; // <freq, < timestamp, key>>
    struct MyCmp {
        auto operator()(const p3i& a, const p3i& b) const {
            if (a.first == b.first) return a.second.first < b.second.first;
            return a.first < b.first;
        }
    };

    typedef set<p3i, MyCmp> MySet;
    typedef list<p4i> MyList;
    typedef MyList::iterator MyIter;
    typedef unordered_map<int, MyIter> MyMap;

public:
    int cap;
    MySet s;
    MyList l;
    MyMap m;
    int ts;

    LFUCache(int capacity) {
        cap = capacity;
        s.clear();
        l.clear();
        m.clear();
        ts = 0;
    }

    int get(int key) {
        if (cap == 0) return -1;
        ++ts;
        auto it = m.find(key);
        if (it == m.end()) return -1;
        
        // update the freq and ts
        /*
            1. Erase the last element from sorted set
            2. Insert the new element in set
        */
        auto lit = it->second;
        s.erase({ lit->second.second.first, {lit->second.second.second, key}});
        lit->second.second.first += 1;
        lit->second.second.second = ts;
        s.insert({ lit->second.second.first, {lit->second.second.second, key} });

        return lit->second.first;
    }

    void add(int key, int value) {
        l.push_front({ key,{value, {1, ts}} });
        s.insert({ 1, {ts, key} });
        m[key] = l.begin();
    }
    /*
        1. First remove the element which is on top of sorted set
        2. remove the same from linklist
        3. remove from map
    */
    void del() {
        int key = s.begin()->second.second;
        s.erase(s.begin());
        auto lit = m[key];
        l.erase(lit);
        m.erase(key);
    }

    void put(int key, int value) {
        if (cap == 0) return;
        ++ts;
        auto it = m.find(key);
        if (it == m.end()) {
            // key don't exist
            int size = s.size();
            if (size == cap) {
                // I am doing to make the space for new element
                del();
            }
            add(key, value);
        }
        else
        {
            // when your key is already present in cache??
            // update the value of freq, ts, and value
            auto lit = it->second;
            s.erase({ lit->second.second.first, {lit->second.second.second, key} });
            lit->second.second.first += 1;
            lit->second.second.second = ts;
            s.insert({ lit->second.second.first, {lit->second.second.second, key} });
            lit->second.first = value;
        }
    }
};

int main(void)
{
    int ans;

/*
    LFUCache lfu(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    ans = lfu.get(1);      // return 1
    cout << ans << endl;

    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    ans = lfu.get(2);      // return -1 (not found)
    cout << ans << endl;

    ans = lfu.get(3);      // return 3
    cout << ans << endl;

    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    ans = lfu.get(1);      // return -1 (not found)
    cout << ans << endl;

    ans = lfu.get(3);      // return 3
    cout << ans << endl;

    // cache=[3,4], cnt(4)=1, cnt(3)=3
    ans = lfu.get(4);      // return 4
    cout << ans << endl;
    // cache=[4,3], cnt(4)=2, cnt(3)=3
*/
    LFUCache lfu(1);
    lfu.put(2, 1);
    ans = lfu.get(2);
    cout << ans << endl;




    return 0;
}

#endif // FORREF
