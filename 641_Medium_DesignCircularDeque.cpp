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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class MyCircularDeque {
public:
    int capacity;
    int size;
    ListNode* head, * tail;

    MyCircularDeque(int k) {
        capacity = k, size = 0;
        head = tail = nullptr;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        ListNode* node = new ListNode(value);
        if (head == nullptr) {
            head = tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        ListNode* node = new ListNode(value);
        if (head == nullptr) {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (head) {
            head = head->next;
            if (!head) tail = nullptr;
        }
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            if (curr == tail) break;
            prev = curr;
            curr = curr->next;
        }
        if (nullptr == prev) {
            head = tail = nullptr;
        }
        else {
            tail = prev;
            if(prev) prev->next = nullptr;
        }
        --size;
        return true;
    }

    int getFront() {
        if (head) return head->val;
        return -1;
    }

    int getRear() {
        if (tail) return tail->val;
        return -1;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull() {
        return size == capacity;
    }
};
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(void)
{

    return 0;
}

#endif // FORREF