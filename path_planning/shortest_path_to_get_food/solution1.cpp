#include <queue>
using namespace std;

class Solution {
    //BFS
public:
    int getFood(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        //find '*'
        pair<int, int> start;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c]=='*') start = {r, c};
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push(start);
        int minDist = 0;
        int size;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> entry = q.front();
                q.pop();
                int r = entry.first, c = entry.second;
                if(grid[r][c]=='#') return minDist;
                if(grid[r][c]=='.') continue;
                grid[r][c] = '.';
                for(auto& d : dirs){
                    int nr = r + d[0], nc = c + d[1];
                    if(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && (grid[nr][nc]=='O' || grid[nr][nc]=='#'))
                        q.push({nr, nc});
                }
            }
            minDist++; 
        }
        return -1;
    }
};