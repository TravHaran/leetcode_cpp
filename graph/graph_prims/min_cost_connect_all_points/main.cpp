#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    // Prim's Algorithm (MST)
    // Time: O(N^2), Space: O(N)
public:
    int manhattan(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 0});
        unordered_set<int> visited;
        int result = 0;
        while(!minHeap.empty()){
            pair<int, int> entry = minHeap.top();
            minHeap.pop();
            int weight = entry.first;
            int node = entry.second;
            if(visited.count(node)) continue;
            visited.insert(node);
            result += weight;
            for(int i = 0; i < points.size(); i++){
                if(!visited.count(i)){
                    int newWeight = manhattan(points[node][0], points[node][1], points[i][0], points[i][1]);
                    minHeap.push({newWeight, i});
                }
            }
        }
        return result;
    }
};