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

// Approach_01

class MyCircularQueue {
    vector<int> varr;
    int fr, bk;
    int capa;

public:
    MyCircularQueue(int k) {
        capa = k;
        varr.resize(3);
        fr = bk = 0;

    }
    bool enQueue(int value) {
        if (isFull())
        {
            cout << "Circular Queue is Full!!! => Please clean some element first." << endl;
            return false;
        }

        if (bk == capa) {
            bk %= capa;
        }
        varr[bk++] = value;
    }
    bool deQueue() {
        // check first that Queue is Empty?
        if (isEmpty()) {
            cout << "Queue is Empty and there is no element for Deque!!" << endl;
            return false;
        }
        
        fr++;
        if (fr == capa) {
            fr %= capa;
        }

        return true;
    }
    int Front() {
        if (isEmpty()) {
            cout << "Info : Queue is Empty and so Front Method Failed..." << endl;
            return -1; // your front method call failed because Queue is Empty
        }
        return varr[fr];
    }

    int Rear() {
        if (isEmpty()) {
            cout << "Info : Queue is Empty and so Rear Method Failed..." << endl;
            return -1; // your Rear method call failed because Queue is Empty
        }

        if (bk == 0) {
            return varr[capa - 1];
        }
        else
            return varr[bk - 1];
    }

    bool isEmpty() {
        if (fr == bk && fr == 0) {
            fr = bk = 0;
            return true;
        }
        return false;
    }
    bool isFull() {
        if (fr < bk)
            return ((bk - fr) == capa) ? true : false;
        else if (bk < fr) {
            return (bk + 1 == fr) ? true : false;
        }
        return false;
    }
};

int main(void)
{
    MyCircularQueue myCircularQueue(3);
    bool ret = myCircularQueue.enQueue(1); // return True
    ret = myCircularQueue.enQueue(2); // return True
    ret = myCircularQueue.enQueue(3); // return True
    ret = myCircularQueue.enQueue(4); // return False
    int val = myCircularQueue.Rear();     // return 3
    ret = myCircularQueue.isFull();   // return True
    ret = myCircularQueue.deQueue();  // return True
    ret = myCircularQueue.enQueue(4); // return True
    val = myCircularQueue.Rear();     // return 4

    return 0;
}

#endif // FORREF