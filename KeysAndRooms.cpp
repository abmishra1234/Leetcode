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
class Solution {
public:
    /*
        As per problem statement return true only if
        you can able to reach all the rooms by exploring the sequence
        
        In problem it is given that, your 0th room is opened so any time 
        you can go inside this room and their after you have to move the 
        room's whose key you will fins inside this room.
    */

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int) rooms.size();
        //cout << "Number of rooms = " << n << endl;
        // As per the problem room 0 can be accessible, so you can just start 
        // from room 0

        vector<int> visited(n, false);
        queue<int> q;
        int room_cnt = 0;

        q.push(0);
        visited[0] = true;
        ++room_cnt;

        while (q.empty() == false) {
            int r = q.front();
            q.pop();

            for (auto rn : rooms[r]) {
                if (visited[rn] == false) {
                    room_cnt++;
                    visited[rn] = true;
                    q.push(rn);
                }
            }
        }
        return (room_cnt == n);
    }
};

Solution sln;

int main(void)
{
    vector<vector<int>> rooms;
    rooms = { {1}, {2}, {3}, {} };
    cout << sln.canVisitAllRooms(rooms) << endl; // true

    rooms = { {1,3} ,{3,0,1},{2},{0} };
    cout << sln.canVisitAllRooms(rooms) << endl; // false



    return 0;
}

#endif // FORREF