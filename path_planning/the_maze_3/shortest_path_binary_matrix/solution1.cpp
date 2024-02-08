#include <deque>
#include <vector>

using namespace std;

class Solution {
    // Time: O(N), Space: O(N), where N is the number of cells in the grid
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if(grid[0][0]==1) return -1;
        deque<pair<int, int>> q{{0, 0}};
        int size;
        pair<int, int> node;
        int r;
        int c;
        int length = 1;
        vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // eight directions of neighbors
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                node = q.front();
                r = node.first;
                c = node.second;
                if(r==ROWS-1 && c==COLS-1) return length;
                q.pop_front();
                for(auto n : neighbors){
                    int dr = r + n.first;
                    int dc = c + n.second;
                    if(min(dr, dc) < 0 || dr > ROWS-1 || dc > COLS-1 || grid[dr][dc] > 0) continue;
                    q.push_back({dr, dc});
                    grid[dr][dc] = 2; // mark as visited
                }
            }
            length++;
        }
        return -1;
    }
};