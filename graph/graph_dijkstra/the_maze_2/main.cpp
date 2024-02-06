#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int ROWS = maze.size();
        int COLS = maze[0].size();
        unordered_set<pair<int, int>> visited;
        vector<vector<int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.
    }
};