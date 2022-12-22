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
#include<queue>

#define FORREF
#ifndef FORREF
/*
    //----------------------------- Approach 01

    When I starting reading this problem, my first thought is to handle this with
    some checks and some set DS by creating two different set and achieve the solution.

    This Approach might work in some scenario or on simple test cases but it start
    failing and identifying the issue is not at all intuitive.

    So this Approch could not be a great solution for this problem.

    //------------------------------------

    When I read this problem again , If i just go by name than it is saying that
    if you can make sure that you can prove the given condition will able to divide
    the group into two set of people without any violation of rule is your solution

    And, with some careful thought I found that if I can prove that with two color ,
    I can able to paint the color of all the vertex , meaning if you can paint all the
    people with only two color such that no two people having dislike with same color
    than wow!! you are able to divide this into two color group of people, right?

    So this approach is to just simply do the coloring of all the people using BFS/DFS
    and if you can without violating any dislike comndition in problem than you are done.

    Let's code this approach and we have also another approach which
    i Will discuss after completing this code.

*/

class Solution {
public:
    // This method for updating the adjlist
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {



        return true;
    }
};

Solution sln;

// Let's write some verificaion code 
int main(void)
{
    int n;
    bool ans;
    vector<vector<int>> dislikes;


    n = 4;
    dislikes = { {1,2}, { 1,3}, {2,4} };
    ans = sln.possibleBipartition(n, dislikes);

    if (ans == true) cout << "1. PASS" << endl;

    n = 3;
    dislikes = { {1,2}, { 1,3}, {2,3} };
    ans = sln.possibleBipartition(n, dislikes);

    if (ans == false) cout << "2. PASS" << endl;

    n = 5;
    dislikes = { {1,2},{2,3}, {3,4}, {4,5}, {1,5} };
    ans = sln.possibleBipartition(n, dislikes);

    if (ans == false) cout << "3. PASS" << endl;

    n = 5;
    dislikes = { {1,2},{3,4}, {4,5}, {3,5} };
    ans = sln.possibleBipartition(n, dislikes);

    if (ans == false) cout << "4. PASS" << endl;



    return 0;
}

#endif // FORREF