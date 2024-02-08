#include <vector>
#include <queue>
using namespace std;

class Solution {
    /**
     * Dijkstra
     * Time: O(m*n*log(m*n))
     *  A complete traversal of the maze will be done in the worst case
     *  This results in O(m*n) operations
     *  getting the min ditance node from the min Heap is O(log(m*n)) in worst case
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
        // we will use a minHeap to store each position we visit
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        //traverse from the start
        distances[start[0]][start[1]] = 0;
        q.push({0, {start[0], start[1]}});
        while(!q.empty()){
            pair<int, pair<int, int>> entry = q.top();
            q.pop();
            int cur_dist = entry.first;
            int r = entry.second.first;
            int c = entry.second.second;
            if(r == destination[0] && c == destination[1]) return cur_dist;
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
                    distances[nr][nc] = distances[r][c] + dist;
                    q.push({distances[nr][nc], {nr, nc}});
                    
                }
            }
        }
        return -1;  
    }
};