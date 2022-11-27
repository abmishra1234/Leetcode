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

//#define FORREF
#ifndef FORREF

class MyCircularQueue {
    vector<int> varr;
    int fr, bk;
    int capa;

public:
    MyCircularQueue(int k) {
        capa = k;
        varr.reserve(3);
        fr = bk = 0;

    }

    bool enQueue(int value) {

    }

    bool deQueue() {

    }

    int Front() {

    }

    int Rear() {

    }

    bool isEmpty() {
        return (fr == bk);
    }

    bool isFull() {
        if (capa == (bk-fr+1) || bk + 1 = fr) {

        }

        return true;
    }
};

int main(void)
{
    MyCircularQueue myCircularQueue(3);
    myCircularQueue.enQueue(1); // return True
    myCircularQueue.enQueue(2); // return True
    myCircularQueue.enQueue(3); // return True
    myCircularQueue.enQueue(4); // return False
    myCircularQueue.Rear();     // return 3
    myCircularQueue.isFull();   // return True
    myCircularQueue.deQueue();  // return True
    myCircularQueue.enQueue(4); // return True
    myCircularQueue.Rear();     // return 4

    return 0;
}

#endif // FORREF