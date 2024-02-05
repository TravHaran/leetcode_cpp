#include <vector>
using namespace std;

class Solution {
    // Time: O(M*N), Space: O(N);
    // traverse graph and keep running count of max size.
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        int size;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c]==1){
                    size = 0;
                    dfs(grid, r, c, size);
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;  
    }

    void dfs(vector<vector<int>>&grid, int r, int c, int& size){
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if(min(r, c) < 0 || r > ROWS-1 || c > COLS-1 || grid[r][c]==0) return;
        grid[r][c]=0;
        size++;
        dfs(grid, r+1, c, size);
        dfs(grid, r-1, c, size);
        dfs(grid, r, c+1, size);
        dfs(grid, r, c-1, size);
    }
};