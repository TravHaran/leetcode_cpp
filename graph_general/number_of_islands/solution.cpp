#include <vector>
using namespace std;

class Solution {
    // linear scan the 2d grid, if a node contains a '1', then it is a root node
    // this triggers a DFS, during which every visited node is set to '0'
    // count the number of root nodes that trigger dfs as each DFS starting at some root 
    //  identifies an island
    // Time: O(M*N), Space: O(M*N)
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int numIslands = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c]=='1'){
                    numIslands++;
                    dfs(grid, r, c);
                }
            }
        }
        return numIslands;   
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(min(r,c) < 0 || r > grid.size()-1 || c > grid[0].size()-1 || grid[r][c]=='0') return;
        grid[r][c]='0';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
};