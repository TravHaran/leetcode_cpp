#include <set>
#include <vector>
using namespace std;

class Solution {
    // dfs traversal to identify islands
    // identify identical islands by setting an origin row and col for at the root node of each island and subtracting every coordinate in the island by these origins
    // use a hash set to store every island encountered
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        set<set<pair<int,int>>> distinctIslands;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c]==1){
                    set<pair<int, int>> island;
                    int rowOrigin = r;
                    int colOrigin = c;
                    dfs(grid, r, c, rowOrigin, colOrigin, island);
                    distinctIslands.insert(island);
                }
            }
        }
        return distinctIslands.size();
    }
    void dfs(vector<vector<int>>& grid, int r, int c, int rowOrigin, int colOrigin, set<pair<int, int>>& island){
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if(min(r, c) < 0 || r > ROWS-1 || c > COLS-1 || grid[r][c]==0) return;
        grid[r][c]=0;
        island.insert({r-rowOrigin, c-colOrigin});
        dfs(grid, r+1, c, rowOrigin, colOrigin, island);
        dfs(grid, r-1, c, rowOrigin, colOrigin, island);
        dfs(grid, r, c+1, rowOrigin, colOrigin, island);
        dfs(grid, r, c-1, rowOrigin, colOrigin, island);
    }
};