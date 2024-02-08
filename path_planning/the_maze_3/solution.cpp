#include <vector>
#include <string>
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
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int ROWS = maze.size(), COLS = maze[0].size();
        // define the directions we can travel 
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // define their corresponding lexicographical instructions
        vector<char> dir_instruct = {'d', 'u', 'r', 'l'};
        // define a matrix of size maze with which we can update the min distance from start to reach each position
        vector<vector<int>> dist(ROWS, (vector<int>(COLS, INT32_MAX)));
        dist[ball[0]][ball[1]] = 0;
        // we will store the positions and the lexicographical instructions in a minHeap
        priority_queue<tuple<int, string, int, int>, vector<tuple<int, string, int, int>>, greater<>> minHeap;
        minHeap.push({0, "", ball[0], ball[1]});
        while(!minHeap.empty()){
            tuple<int, string, int, int> entry = minHeap.top();
            minHeap.pop();
            int cur_dist = get<0>(entry);
            string instruction = get<1>(entry);
            int r = get<2>(entry);
            int c = get<3>(entry);
            if(r == hole[0] && c == hole[1]) return instruction;
            for(int i = 0; i < 4; i++){
                bool hole_found = false;
                int nr = r + dirs[i][0], nc = c + dirs[i][1], steps = 1;
                while(min(nr, nc) >= 0 && nr < ROWS && nc < COLS && maze[nr][nc]==0){
                    if(nr == hole[0] && nc == hole[1]){
                        hole_found = true;
                        break;
                    } 
                    nr += dirs[i][0];
                    nc += dirs[i][1];
                    steps++;
                }
                // revert to position before hitting wall
                if(!hole_found){
                    nr -= dirs[i][0];
                    nc -= dirs[i][1];
                    steps--;
                }
                //as long as the ball is moving, the distance must be increasing,
                //so to avoid dead loop, we have to let the ball run (exclude the stopping ball case)
                if((nr != r || nc!= c) && steps + dist[r][c] <= dist[nr][nc]){
                    dist[nr][nc] = steps + dist[r][c];
                    minHeap.push({dist[nr][nc], instruction+dir_instruct[i], nr, nc});
                }
            }
        }
        return "impossible"; 
    }
};