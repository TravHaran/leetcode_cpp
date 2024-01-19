#include <vector>
using namespace std;

class Solution {
    /**
     * From the top, the shadow made by the shape will be 1 square for each non-zero value.
     * From the side, the shadow made by the shape will be the largest value for each row in the grid.
     * From the front, the shadow made by the shape will be the largest value for each column in the grid.
    */
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
        int maxCol;
        int maxRow;
        for(int r = 0; r < grid.size(); r++){
            maxCol = 0;
            maxRow = 0;
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c]>0) area++; // top 
                maxCol = max(maxCol, grid[r][c]); // side 
                maxRow = max(maxRow, grid[c][r]); // front
            }
            area += maxRow + maxCol;
        }
        return area;
    }
};