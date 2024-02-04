#include <queue>
#include <set>
using namespace std;

class Solution {
    // Dijkstra's Shortest Path Algorithm: O(E*logV) where E is the number of edges, and V is the number of nodes
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        set<pair<int, int>> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({0, {0, 0}});
        vector<vector<int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // up, down, right, left

        while(!minHeap.empty()){
            pair<int, pair<int, int>> entry = minHeap.top();
            minHeap.pop();
            int weight = entry.first;
            int r = entry.second.first;
            int c = entry.second.second;

            if(r == ROWS - 1 && c == COLS - 1) return weight;
            
            if(visited.count(entry.second)) continue;

            visited.insert(entry.second);
            for(auto& n : neighbors){
                int nr = r + n[0];
                int nc = c + n[1];
                if(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && !visited.count({nr, nc})){
                    int minEffort = max(weight, abs(heights[r][c] - heights[nr][nc]));
                    minHeap.push({minEffort, {nr, nc}});
                }
            }
        }
        return -1;
    }
};