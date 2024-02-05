#include <vector>
#include <deque>
using namespace std;

class Solution {
    // Time: O(N*M) where N*M is the size of the grid, Space: O(N*M)
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh_count = 0;
        deque<pair<int, int>> q;
        // linear search matrix to count all fresh oranges, and add all rotten oranges to queue
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c]==1) fresh_count++;
                else if (grid[r][c]==2){
                    q.push_back({r, c});
                } 
            }
        }
        if(fresh_count==0) return 0; // handle edge case
        int size;
        pair<int,int> coord;
        vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // define adjacent neighbors
        int r;
        int c;
        int dr;
        int dc;
        int rot_count = 0;
        int steps = 0;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                coord = q.front();
                r = coord.first;
                c = coord.second;
                if(grid[r][c]==1){ // every time an orange rots we increment counter
                    grid[r][c] = 2;
                    rot_count++;
                }
                if(rot_count==fresh_count) return steps; // if all fresh oranges have gone rotten return steps taken
                grid[r][c] = -1; // we modify the coordinate to indicate that it's visited
                q.pop_front();
                for(auto n : neighbors){
                    dr = r + n.first;
                    dc = c + n.second;
                    if(min(dr, dc)<0 || dr>=ROWS || dc>=COLS || grid[dr][dc]==-1 || grid[dr][dc]!=1) continue;
                    q.push_back({dr, dc});
                }
            }
            steps++; // increment count of steps taken in traversal
        }
        // if we reach the end that means not all fresh oranges have gone rotten
        return -1; 
    }
};