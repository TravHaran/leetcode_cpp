#include <set>
#include <queue>
using namespace std;

class Solution {
    //Dijkstra's Shortest Path Algorithm
    // Time: O(n^2*log(n))
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});
        set<pair<int, int>> visited;
        vector<vector<int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!minHeap.empty()){
            pair<int, pair<int, int>> entry = minHeap.top();
            int time = entry.first;
            int r = entry.second.first;
            int c = entry.second.second;
            minHeap.pop();
            if(r == N-1 && c == N-1) return time;
            if(visited.count({r, c})) continue;
            visited.insert({r, c});
            for(auto& n : neighbors){
                int nr = r + n[0];
                int nc = c + n[1];
                if(min(nr, nc) >= 0 && max(nr, nc) < N && !visited.count({nr, nc})){
                    minHeap.push({max(time, grid[nr][nc]), {nr, nc}});
                }
            }
        }
        return -1;
    }
};