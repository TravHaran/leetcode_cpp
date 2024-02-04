#include <set>
#include <queue>
using namespace std;

class Solution {
    //Dijkstra's shortest path algorithm
    // modified to use maxHeap instead
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        maxHeap.push({grid[0][0], {0, 0}});
        set<pair<int, int>> visited;
        vector<vector<int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!maxHeap.empty()){
            pair<int, pair<int, int>> entry = maxHeap.top();
            maxHeap.pop();
            int val = entry.first;
            int r = entry.second.first;
            int c = entry.second.second;
            if(r == ROWS-1 && c == COLS-1) return val;
            if(visited.count({r, c})) continue;
            visited.insert({r, c});
            for(auto& n : neighbors){
                int nr = r + n[0];
                int nc = c + n[1];
                if(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && !visited.count({nr, nc})){
                    maxHeap.push({min(val, grid[nr][nc]), {nr, nc}});
                }
            }
        }
        return -1;
    }
};