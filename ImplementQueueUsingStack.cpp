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
    Many times in past you heard that you can achieve the queue
    like concept using two stack. Let's try to implement it in below
    code.

    For record : 04-Dec-2022, Abinash Mishra
*/

class MyQueue {
    stack<int> inStk; // whenever you have the Enqueue the item
    stack<int> outStk; // whenever you have to Dequeue the item 

public:
    MyQueue() {
        while (inStk.empty() == false) inStk.pop();
        while (outStk.empty() == false) outStk.pop();
    }

    void push(int x) {
        inStk.push(x);
    }

    int pop() {

        int item;
        
        if (outStk.empty()) {
            while (inStk.empty() == false) {
                item = inStk.top();
                outStk.push(item);
                inStk.pop();
            }
        }
       
        item = outStk.top();
        outStk.pop();
        return item;
    }

    int peek() {
        int item;

        if (outStk.empty()) {
            while (inStk.empty() == false) {
                item = inStk.top();
                outStk.push(item);
                inStk.pop();
            }
        }

        return outStk.top(); // if top exist
    }

    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};

/*
    //tc #1
    ["MyQueue","push","push","push","push","pop","push","pop","pop","pop","pop"]
    [[],[1],[2],[3],[4],[],[5],[],[],[],[]]

    @Note: One important point to be noted here that even if 
    problem seems very trivial still write your tc and run for that...
*/

int main(void)
{
    MyQueue *qp = new MyQueue();
    // tc #1
    qp->push(1);
    qp->push(2);
    qp->push(3);
    qp->push(4);

    cout << qp->pop() << endl; // 1

    qp->push(5);

    cout << qp->pop() << endl; // 2
    cout << qp->pop() << endl; // 3
    cout << qp->pop() << endl; // 4
    cout << qp->pop() << endl; // 5







    return 0;
}

#endif // FORREF