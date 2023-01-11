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

class Skiplist {
public:
    vector<vector<int>> nums;
    Skiplist() {
        nums.resize(20005, {});
    }

    bool search(int target) {
        return (nums[target].size() > 0);
    }

    void add(int num) {
        nums[num].push_back(num);
    }

    bool erase(int num) {
        bool result = false;
        if (nums[num].size() > 0) {
            result = true;
            nums[num].pop_back();
        }
        return result;
    }
};
/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main(void)
{



    return 0;
}

#endif // FORREF