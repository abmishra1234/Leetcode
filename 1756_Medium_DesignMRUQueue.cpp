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
    Design a queue-like data structure that moves 
    the most recently used element to the end of the queue.

    Implement the MRQ class:
    a) MRQueue(int n) : constructs the MRQueue with n elements : 1,2,3,...n
    b) int fetch(int k) moves the kth element (1-indexed) to the end of the queue and return it.

    Approach:[Brute Force Approach]
    1. I am using here one dequeue kind of DS
    2. [This might be considered as precompute stage] Initially pushing everything 
       in queue by just pushing back into dequeue
    3. create one stack , pop_front k element and push into stack
    4. a. pop one element from stack and push_back into deque, and backup element in ans variable
    4. b. pop k-1 element and push_front into dequeue
    5. return the ans from this method
*/

class MRUQueue {
    deque<int> q;
public:
    MRUQueue(int n) {
        q.clear();

        for (int i = 1; i <= n; ++i) {
            q.push_back(i);
        }
    }

    int fetch(int k) {
        stack<int> s;

        while (k > 0) {
            int elem = q.front();
            q.pop_front();
            s.push(elem);
            --k;
        }

        int ans = s.top();
        s.pop();
        q.push_back(ans);

        while (false == s.empty()) {
            int elem = s.top();
            s.pop();
            q.push_front(elem);
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF