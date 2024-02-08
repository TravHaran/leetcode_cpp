#include <deque>
#include <set>
#include <vector>

using namespace std;

class Solution {
    /**
     * BFS
     * Time: O(m*n*(m+n))
     * Space: O(m*n)
    */
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int ROWS = maze.size();
        int COLS = maze[0].size();
        // initialize a set to store visited nodes
        set<pair<int, int>> visited;
        // initialize a vector to store all for directions we will travel from each position
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // we will use a queue to store each position we visit
        deque<pair<int, int>> q = {{start[0], start[1]}};
        while(!q.empty()){
            pair<int, int> entry = q.front();
            int r = entry.first;
            int c = entry.second;
            q.pop_front();
            if(r == destination[0] && c == destination[1]) return true;
            if(visited.count({r, c})) continue;
            visited.insert({r, c});
            for(auto& d : dirs){
                r = entry.first;
                c = entry.second;
                // traverse until you hit a wall
                while(min(r, c) >= 0 && r < ROWS && c < COLS && maze[r][c]==0){
                    r += d[0];
                    c += d[1];
                }
                //revert the position to before you hit the wall
                q.push_back({r-d[0], c-d[1]});
            }
        }
        return false;
    }
};