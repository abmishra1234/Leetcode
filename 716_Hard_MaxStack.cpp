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
  Problem:
  Design a max stack data structure that supports the stack operations 
  and supports finding the stack's maximum element.

  Implement the MaxStack class:
  1. MaxStack() Initializes the stack object.
  2. void push(int x) Pushes element x onto the stack.
  3. int pop() Removes the element on top of the stack and returns it.
  4. int top() Gets the element on the top of the stack without removing it.
  5. int peekMax() Retrieves the maximum element in the stack without removing it.
  6. int popMax() Retrieves the maximum element in the stack and removes it. 
     If there is more than one maximum element, only remove the top-most one.
  
  Performance Requirement of your problem:
  You must come up with a solution that supports O(1) for each top call 
  and O(logn) for each other call.


Approach:
    I will use one List class, which is Doubly Linklist, Sorted Set
*/

typedef pair<int, int> pii; // <value, pos>
typedef list<pii> MyList;
typedef MyList::iterator MyIter;
struct MySort {
    auto operator()(const pii& a, const pii& b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
typedef set<pii, MySort> MySet;

// for making one more structure to maintain the mapping [ pos vs MyIter ] 
typedef unordered_map<int, MyIter> MyMap;

class MaxStack {
public:
    
    MyList l;
    MySet s;
    MyMap m;

    int pos;

    MaxStack() {
        l.clear();
        s.clear();
        m.clear();
        pos = 1;
    }

    void push(int x) {
        l.push_front({ x,pos });
        s.insert({ x,pos });
        m[pos] = l.begin();
        ++pos;
    }

    int pop() {
        auto p = l.front();
        s.erase({ p.first, p.second});
        m.erase(p.second);
        l.pop_front();
        return p.first;
    }

    int top() {
        auto it = l.begin();
        return it->first;
    }

    int peekMax() {
        auto it = s.begin();
        return it->first;
    }

    int popMax() {
        auto it = s.begin();
        int ans = it->first;
        l.erase(m[it->second]);
        m.erase(it->second);
        s.erase(it);
        return ans;
    }
};


int main(void)
{
    MaxStack stk;
    stk.push(5);   // [5] the top of the stack and the maximum number is 5.
    stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
    stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
    int ans;
    ans = stk.top();     // return 5, [5, 1, 5] the stack did not change.
    cout << ans << endl;
    ans = stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
    cout << ans << endl;
    ans = stk.top();     // return 1, [5, 1] the stack did not change.
    cout << ans << endl;
    ans = stk.peekMax(); // return 5, [5, 1] the stack did not change.
    cout << ans << endl;
    ans = stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
    cout << ans << endl;
    ans = stk.top();     // return 5, [5] the stack did not change.
    cout << ans << endl;

    return 0;
}

#endif // FORREF
