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

struct MySort {
    auto operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[1] <= b[1];
    }
};

struct MyHash {
    auto operator()(const pair<int, int>& a) const
    {
        return (hash<int>{}(a.first) ^ hash<int>{}(a.second));
    }
};

typedef unordered_map<pair<int, int>, int, MyHash> MyMap;

vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    // Step 01 is sort the array according to value
    sort(arr.begin(), arr.end());


    // Step 02  - You should prepare trie as per requirement only
    // Sort the query according to the value of A[i]
    vector<vector<int>> queries_bkp = queries;
    sort(queries.begin(), queries.end(), MySort());

    // Step 03
    // I will calculate the max value for the queries and push this 
    // pair of {query vs max value } into some solution map to
    // return the output later according to the queries
    
    Trie t;
    MyMap m;

    for (int i = 0; i < (int) queries.size(); ++i) {
        int ai = queries[i][0];
        int xi = queries[i][1];

        vector<int> nums;

        for (int j = 0; j < arr.size(); ++j) {
            if (arr[j] < xi) {
                nums.push_back(arr[j]);
            }
        }
        
        if (nums.size() == 0) {
            m.insert({ { ai,xi }, -1 });
        }
        else
        {
            // insert into trie
            t.insertnums(nums);
            int val = t.getMaxValue(ai);
            m.insert({ { ai,xi }, val });
        }
    }

    vector<int> ans;
    for (int i = 0; i < queries_bkp.size(); ++i) {
        ans.push_back(m[{queries_bkp[i][0], queries_bkp[i][1]}]);
    }

    return ans;
}


/*
    5 -1 15
    1 1 
*/

int main(void)
{
    FILE* fp;
    freopen_s(&fp, "maxXOR.txt", "r", stdin);
    
    int T, N, Q;
    cin >> T;

    vector<int> arr;
    vector<vector<int>> queries;

    for (int t = 1; t <= T; ++t) {
        cin >> N; cin >> Q;
        arr.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        queries.resize(Q);
        vector<int> v;
        for (int i = 0; i < Q; ++i) {
            v.resize(2);
            cin >> v[0]; cin >> v[1];
            queries[i] = v;
        }
        vector<int> ans = maxXorQueries(arr, queries);
        for (auto n : ans) cout << n << " ";
        cout << endl;
    }

    //arr.clear();
    //queries.clear();

    return 0;
}

/*

Help:
#include<bits/stdc++.h>
struct Node {
    Node *links[2];

    bool containsKey(int ind) {
        return (links[ind] != NULL);
    }
    Node* get(int ind) {
        return links[ind];
    }
    void put(int ind, Node* node) {
        links[ind] = node;
    }
};
class Trie {
    private: Node* root;
public:
    Trie() {
        root = new Node();
    }

    public:
    void insert(int num) {
        Node* node = root;
        // cout << num << endl;
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    public:
    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1<<i);
                node = node->get(!bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int,int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    int n = arr.size();
    Trie trie;

    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]);
            i++;
        }
        if(i!=0) ans[it.second.second] = trie.findMax(it.second.first);
        else ans[it.second.second] = -1;
    }
    return ans;
}














*/




#endif // FORREF