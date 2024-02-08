#include <vector>
#include <queue>
using namespace std;

class Solution {
    /**
     * A* Search algorithm
    */
public:
    int manhattan(pair<int, int> pos, vector<pair<int, int>>& foods){
        int r = pos.first,  c = pos.second;
        int val = INT32_MAX;
        for(auto& [fr, fc] : foods){
            val = min(val, abs(fr - r) + abs(fc - c));
        }
        return val;
    }

    int getFood(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // find the start position and food locations
        pair<int, int> start;
        vector<pair<int, int>> foods;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c]=='*') start = {r, c};
                else if(grid[r][c]=='#') foods.push_back({r, c});
            }
        }
        // handle edge case of no foods on grid
        if(foods.empty()) return -1;
        // in our priority queue we will store the heuristic distance, the steps taken, and the node
        priority_queue<tuple<int, int, pair<int, int>>, vector<tuple<int, int, pair<int, int>>>, greater<>> minHeap;
        // start A* search at start
        minHeap.push({manhattan(start, foods), 0, start});
        while(!minHeap.empty()){
            tuple<int, int, pair<int, int>> entry = minHeap.top();
            int cur_est = get<0>(entry);
            int steps = get<1>(entry);
            int r = get<2>(entry).first;
            int c = get<2>(entry).second;
            minHeap.pop();
            if(grid[r][c]=='#') return steps;
            // mark as visited
            grid[r][c] = '.';
            for(auto& d : dirs){
                int nr = r + d[0], nc = c + d[1];
                if(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && (grid[nr][nc] == '#' || grid[nr][nc] == 'O')){
                    int new_est = manhattan({nr, nc}, foods);
                    minHeap.push({new_est, steps + 1, {nr, nc}});
                        
                }
            }  
        }
        return -1;
    }
};