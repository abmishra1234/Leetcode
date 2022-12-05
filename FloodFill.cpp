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

/*
    Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], color < 216
    0 <= sr < m
    0 <= sc < n
*/

#define FORREF
#ifndef FORREF
// L U R B
int xr[4] = { 0, -1, 0, 1 };
int yc[4] = {-1, 0, 1, 0};

class Solution {
public:

    bool Valid(int x, int y, const int& R, const int& C) {
        if (x < 0 || x >= R) return false;
        if (y < 0 || y >= C) return false;

        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, 
        int sr, int sc, int color) {
        
        int R = image.size();
        int C = image[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));

        queue<pair<int, pair<int, int>>> q;
        // push the src first
        q.push({ sr,{sc, color} });
        visited[sr][sc] = true;

        int prev_color = image[sr][sc];
        image[sr][sc] = color;


        while (q.empty() == false) {
            pair<int, pair<int, int>> pii = q.front();
            q.pop();

            int x, y;

            for (int i = 0; i < 4; ++i) {
                x = pii.first + xr[i];
                y = pii.second.first + yc[i];

                if (Valid(x, y, R, C) && visited[x][y] == false && image[x][y] == prev_color) {
                    visited[x][y] = true;
                    image[x][y] = pii.second.second;
                    q.push({ x,{ y , pii.second.second} });
                }
            }
        }
        return image;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF