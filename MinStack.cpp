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

class MinStack {
    stack<int> min_stack;
    stack<int> numstack;

public:
    /** initialize your data structure here. */
    MinStack() : min_stack(), numstack() {
    }

    void push(int x) {
        // push element into numstack
        numstack.push(x);
        // new element is smaller or equal to the element on the top of minstack 
        if (min_stack.size() == 0)
            min_stack.push(x);
        else if (x <= min_stack.top()) {
            min_stack.push(x);
        }
    }

    void pop() {
        if (numstack.top() == min_stack.top()) {
            numstack.pop();
            min_stack.pop();
        }
        else
            numstack.pop();
    }

    int top() {
        return numstack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

MinStack sln;


int main(void)
{

    return 0;
}

#endif // FORREF