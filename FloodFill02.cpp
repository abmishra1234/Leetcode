// https://www.codingninjas.com/codestudio/problems/flood-fill-algorithm_1089687
// Flood Fill Algorithm

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

class Solution {
public:
    void flood(int r, int c, vector<vector<int>>& image,
        int newcolor, const int oldcolor, const int& R, const int& C) {
        if (r < 0 || r >= R) return;
        if (c < 0 || c >= C) return;
        if (image[r][c] != oldcolor) return;
        if (image[r][c] == newcolor) return;

        image[r][c] = newcolor;
        // now you have to just call the all adjacent cell
        // left
        flood(r, c - 1, image, newcolor, oldcolor, R, C);
        // up
        flood(r - 1, c, image, newcolor, oldcolor, R, C);
        // right
        flood(r, c + 1, image, newcolor, oldcolor, R, C);
        // down
        flood(r + 1, c, image, newcolor, oldcolor, R, C);
    }

    // Flood Fill Algorithm
    vector<vector<int>> floodFill(vector<vector<int>>& image,
        int x, int y, int newColor)
    {
        flood(x, y, image, newColor, image[x][y], image.size(), image[0].size());
        return image;
    }
};

Solution sln;

int main(void)
{


    return 0;
}

#endif // FORREF

