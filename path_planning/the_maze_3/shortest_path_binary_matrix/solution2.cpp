#include <queue>
#include <vector>
using namespace std;

class Solution {
    // Dijkstra
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if(grid[0][0]==1) return -1;
        vector<vector<int>> distances(ROWS, (vector<int>(COLS,INT32_MAX)));
        // store the directions we can travel in a list
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                                    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        // we will store the distances travelled in a minHeap
        queue<pair<int, pair<int, int>>> minHeap;
        minHeap.push({1, {0, 0}});
        distances[0][0] = 1;
        while(!minHeap.empty()){
            pair<int, pair<int, int>> entry = minHeap.front();
            minHeap.pop();
            int dist = entry.first;
            int r = entry.second.first;
            int c = entry.second.second;
            if(r == ROWS-1 && c == COLS-1) return dist;
            for(auto& d : dirs){
                int nr = r + d[0], nc = c + d[1];
                if(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && grid[nr][nc]==0 && distances[nr][nc] > dist+1){
                    distances[nr][nc] = dist+1;
                    minHeap.push({distances[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
    }
};