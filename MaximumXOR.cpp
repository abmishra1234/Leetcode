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
struct Node {
    Node* childs[2];
    
    void init() {
        childs[0] = childs[1] = nullptr;
    }

    bool contain(int n) {
        return childs[n] != nullptr;
    }

    Node* get(int n) {
        return childs[n];
    }

    void put(int n, Node* np) {
        np->init();
        childs[n] = np;
    }

}; // pool[200000];
int pind;

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node(); // &pool[pind++];
        root->init();
    }

    void insertword(vector<int> nums) {
        Node* start = root;
       
        for (int i = 0; i < 32; ++i) {
            if (!start->contain(nums[i])) {
                start->put(nums[i], new Node());
            }
            start = start->get(nums[i]);
        }
    }

    // I will try to achieve the same with bitset concept also later
    vector<int> getbinnums(int n) {
        // Convert the given number into the bitstr
        vector<int> nums(32, 0);
        int npos = 31;
        while (n > 0) {
            nums[npos--] = n % 2;
            n /= 2;
        }
        return nums;
    }

    void insertnums(vector<int>& nums) {
        for (auto n : nums) {
            vector<int> binnum = getbinnums(n);
            insertword(binnum);
        }
    }

    // Here also we will try to achieve this using some bit manipultion concept
    int convbitnum2val(vector<int> nums) {
        int val = 0;
        // Write your conversion logic below and finally return the val
        int fact = 1;
        for (int i = 31; i >= 0; --i) {
            val += (nums[i] * fact);
            fact *= 2;
        }
        return val;
    }

    /*
        This method is for getting the maximum possible value
        with the given number and created Trie DS with other 
        complete array. 
        <Info>
        Most of the key logic is at two place only
        1. Populating the Trie DS
        2. How to fetch the max value corresponding to the given n 
        and populated DS
    */
    int getMaxValue(int n) {
        // Write your logic below, such a way that it will give you the max
        // value after XOR
        vector<int> bitnum = getbinnums(n);

        vector<int> resbitnum(32, 0);
        Node* start = root;

        int trgbit;

        for (int i = 0; i < 32; ++i) {
            trgbit = 1 - bitnum[i];
            if (!start->contain(trgbit)) {
                resbitnum[i] = 0;
            }
            else resbitnum[i] = 1;
            start = (resbitnum[i] == 1) ? start->get(trgbit) : start->get(1 - trgbit);
        }

        return convbitnum2val(resbitnum);
    }
};

int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2)
{
    Trie t;
    
    // Let's complete the first step
    t.insertnums(arr1);

    // Let's concentrate on second step
    int maxv = -1;
    for (auto n : arr2) {
        int val = t.getMaxValue(n);
        maxv = max(maxv, val);
    }

    return maxv;
}


int main(void)
{
    int n, m;
    vector<int> arr1, arr2;
    int ans;

    // #tc 1
    n = m = 7;
    arr1 = { 6, 6, 0, 6, 8, 5, 6 };
    arr2 = { 1, 7, 1, 7, 8, 0, 2 };

    ans = maxXOR(n, m, arr1, arr2);
    cout << " 15 = " << ans << endl;


    return 0;
}

#endif // FORREF