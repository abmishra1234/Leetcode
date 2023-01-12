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

//#define FORREF
#ifndef FORREF

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

/*
    @NOTE : It is hard problem in my opinion

    Constraints:
    1 <= val <= 10^9
    At most 1000 calls will be made to pushFront, pushMiddle, 
    pushBack, popFront, popMiddle, and popBack.

    This is really a good thoughful problem and you need to write
    some kind of psuedo code for this problem first??

    Approach 01:

    Summary - Let's build Doubly Link List and create 03 pointer
    head, mid and tail. manage all these pointers with all the 
    required validation of these pointers and done


    When you are designing somethig meaningful code reusability is one 
    of the key concept in good design and better code maintainability??


    
*/

/*
Hint
    For an O(1) per method approach, 
    use 2 double-ended queues: 
    one for the first half 
    and one for the second half.
*/

class FrontMiddleBackQueue {
    deque<int> fh, sh;
public:
    FrontMiddleBackQueue() {
        fh.clear(); sh.clear();
    }
    void pushFront(int val) {
        fh.push_front(val);

        int s1 = fh.size();
        int s2 = sh.size();
        if (s1 == s2 || s1 == (1 + s2)) return;

        sh.push_front(fh.back());
        fh.pop_back();
    }
    void pushMiddle(int val) {
        int s1 = fh.size();
        int s2 = sh.size();

        if (s1 <= s2) {
            fh.push_back(val);
        }
        else
        {
            sh.push_front(fh.back());
            fh.pop_back();
            fh.push_back(val);
        }
    }
    void pushBack(int val) {
        sh.push_back(val);

        int s1 = fh.size();
        int s2 = sh.size();

        if (s1 == s2) return;

        fh.push_back(sh.front());
        sh.pop_front();
    }
    int popFront() {
        int result = -1;
        int s1 = fh.size();
        int s2 = sh.size();

        if (s1 > 0) {
            result = fh.front();
            fh.pop_front();
        }
        else
        {
            if (s2 > 0) {
                result = sh.front();
                sh.pop_front();
            }
        }

        s1 = fh.size();
        s2 = sh.size();

        while (s2 > s1) {
            fh.push_back(sh.front());
            sh.pop_front();
            ++s1; --s2;
        }

        return result;
    }
    int popMiddle() {
        int result = -1;
        int s1 = fh.size();
        int s2 = sh.size();

        if (s1 > 0) {
            result = fh.back();
            fh.pop_back();
        }
        else
        {
            if (s2 > 0) {
                result = sh.front();
                sh.pop_front();
            }
        }

        s1 = fh.size();
        s2 = sh.size();

        if (s1 == s2 || s1 == (1 + s2)) return result;

        if (s1 > s2) {
            while (s1 > (1 + s2)) {
                sh.push_front(fh.back());
                fh.pop_back();
                --s1; ++s2;
            }
        }
        else if (s1 < s2) {
            while (s2 > s1) {
                fh.push_back(sh.front());
                sh.pop_front();
                ++s1; --s2;
            }
        }

        return result;
    }
    int popBack() {
        int result = -1;
        int s2 = sh.size();
        int s1 = fh.size();

        if (s2 > 0) {
            result = sh.back();
            sh.pop_back();
        }
        else
        {
            if (s1 > 0) {
                result = fh.back();
                fh.pop_back();
            }
        }

        s1 = fh.size();
        s2 = sh.size();

        while (s1 > (1 + s2)) {
            sh.push_front(fh.back());
            fh.pop_back();
            --s1; ++s2;
        }

        return result;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

FrontMiddleBackQueue q;


int main(void)
{
    int ans = q.popMiddle();
    if (ans == -1) cout << "1. PASS" << endl;



    return 0;
}

#endif // FORREF