#include <vector>
#include <deque>
using namespace std;

class Solution {
    /**
     * BFS
     * Time: O(m*n*(max(m, n)))
     *  A complete traversal of the maze will be done in the worst case
     *  This results in O(m*n) operations
     *  For each node selected in this process we can travel a max depth of m or n until we hit a wall
     *  This results in O(max(m, n)) operations
     * Space: O(m*n)
     *  the distances matrix is the size of the maze and the queue can grow to the size of the maze
    */
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int ROWS = maze.size();
        int COLS = maze[0].size();
        // create a matrix of size maze
        // update this matrix with min distance traveled from start to get to each position
        vector<vector<int>> distances(ROWS, vector<int>(COLS, INT32_MAX)); 
        // initialize a vector to store all for directions we will travel from each position
        vector<vector<int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        // we will use a queue to store each position we visit
        deque<pair<int, int>> q = {{start[0], start[1]}};
        //traverse from the start
        distances[start[0]][start[1]] = 0;
        while(!q.empty()){
            pair<int, int> entry = q.front();
            q.pop_front();
            int r = entry.first, c = entry.second;
            for(auto& d : dirs){
                int dist = 0;
                int nr = r + d[0], nc = c + d[1];
                // traverse until you hit a wall
                while(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && maze[nr][nc]==0){
                    nr += d[0];
                    nc += d[1];
                    dist++;
                }
                // revert to before you hit the wall
                nr -= d[0], nc -= d[1];
                if(distances[r][c] + dist < distances[nr][nc]){ // update min distance
                    q.push_back({nr, nc});
                    distances[nr][nc] = distances[r][c] + dist;
                }
            }
        }
        int result = distances[destination[0]][destination[1]] == INT32_MAX ? -1 : distances[destination[0]][destination[1]];
        return result;  
    }
};