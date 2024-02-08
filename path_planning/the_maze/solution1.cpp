#include <set>
#include <vector>
using namespace std;

class Solution {
    /**
     * DFS
     * Time: O(m*n*(m+n));
     *  through dfs we visit each node once at most resulting in O(m*n) operations
     *  and for each dfs we loop through each direction 
     *  which would at most take m steps in vertical and n steps in horizontal to reach a wall
     *  resulting in O(m+n) operations
     * Space: O(m*n);
     *  we use a set to keep track of the visited nodes which at most could be all nodes
     *  the recursion call stack could be at most all nodes
    */  
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        // we need to keep track of the visited positions
        set<pair<int, int>> visited;
        // we'll start dfs at the start position
            // in our recursive dfs function we'll traverse all four directions
            // for each direction we continue traversing until we hit a wall
        return dfs(maze, {start[0], start[1]}, destination, visited);
    }

    bool dfs(vector<vector<int>>& maze, pair<int, int> position, vector<int>& destination, set<pair<int, int>>& visited){
        // check if the position has been visited already
        if(visited.count({position})) return false;
        if(position.first == destination[0] && position.second == destination[1]) return true;

        int ROWS = maze.size();
        int COLS = maze[0].size();
        // define directions
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        //add current position to visited
        visited.insert(position);
        for(auto& d : dirs){
            int r = position.first;
            int c = position.second;
            while(min(r, c) >= 0 && r < ROWS && c < COLS && maze[r][c]==0){
                // if the current position is empty continue traversing until we hit a wall
                r += d[0];
                c += d[1];
            }
            // revert the last move to get to the position before the ball hit the wall
            if(dfs(maze, {r - d[0], c - d[1]}, destination, visited)) return true;
        }
        return false;
    }
};