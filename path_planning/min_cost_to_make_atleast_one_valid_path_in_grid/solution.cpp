#include <queue>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ROWS = grid.size();
        int COLS = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<int>> visit(ROWS, vector<int>(COLS , 0));
        minHeap.push({0, {0, 0}});
        while(!minHeap.empty()){
            pair<int, pair<int, int>> entry = minHeap.top();
            minHeap.pop();
            int cost = entry.first;
            int r = entry.second.first;
            int c = entry.second.second;
            if(r == ROWS-1 && c == COLS-1) return cost;
            if(visit[r][c]==1) continue;
            visit[r][c] = 1;
            for(int k = 0; k < 4; k++){
                int nr = r + dirs[k][0];
                int nc = c + dirs[k][1];
                if(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && visit[nr][nc]==0){
                    if(grid[r][c] != k+1)
                        minHeap.push({cost + 1, {nr, nc}});
                    else
                        minHeap.push({cost, {nr, nc}});
                }
            }
        }
        return 0;   
    }
};