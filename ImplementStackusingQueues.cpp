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
/*
    Implement the Stack using standard queue container class
    1. Define some test case for your understanding and verification of your code
     @Comment : Can we implement Stack using one Queue?
*/

class MyStack {
    deque<int> myqueue;
public:
    MyStack() {
        while (myqueue.empty() == false) myqueue.pop_back();
    }

    void push(int x) {
        myqueue.push_back(x);
    }

    int pop() {
        int result = myqueue.back();
        myqueue.pop_back();
        return result;
    }

    int top() {
        return myqueue.back();
    }

    bool empty() {
        return myqueue.empty();
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF