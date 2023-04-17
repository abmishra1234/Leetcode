using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
#ifndef FORREF

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;
        // find the first bar to the left of each bar that is lower than its height
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        // clear the stack
        while (!s.empty()) {
            s.pop();
        }
        // find the first bar to the right of each bar that is lower than its height
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int maxArea = 0;
        // compute the area of the largest rectangle for each bar
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

/*

    This implementation is based on the "largest rectangle in a histogram" algorithm using stacks. 
    We define the largestRectangleArea function as a public member function of the class, 
    which takes a vector of integers heights representing the histogram's bar height where the 
    width of each bar is 1, and returns the area of the largest rectangle in the histogram.

    In the function, we first compute the "left" and "right" limits of each bar using stacks. 
    The "left" limit of a bar is the first bar to the left of it that is lower than its height, and the 
    "right" limit of a bar is the first bar to the right of it that is lower than its height. We use two 
    stacks to compute these limits efficiently in O(n) time.

    Once we have the "left" and "right" limits for each bar, we can compute the 
    area of the largest rectangle for each bar using the formula: height[i] * (right[i] - left[i] - 1). 
    We then take the maximum of these areas as the answer.

*/


int main() {
    Solution s;
    vector<int> heights = { 2, 1, 5, 6, 2, 3 };
    int maxArea = s.largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << maxArea << endl;
    return 0;
}


#endif // FORREF