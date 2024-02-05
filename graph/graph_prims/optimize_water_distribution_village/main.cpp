#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    // Prims Algorithm (MST)
    // Let N be the number of houses, and M be the number of pipes from the input.
    // Time: O((N+M)*log(N+M))
    // Space: O(N+M)
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // build adjacency list
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto& p : pipes){
            // p[0] : node
            // p[1] : neighbor
            // p[2] : weight
            adjList[p[0]].push_back({p[2], p[1]});
            // bidirectional
            adjList[p[1]].push_back({p[2], p[0]});
        }
        // add a virtual node to the graph to represent the cost of building a well at each house
        for(int house = 1; house <= n; house++){
            // let 0 represent the arbitrary node
            adjList[0].push_back({wells[house-1], house});
        }
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 0});
        int result = 0;
        while(!minHeap.empty()){
            pair<int, int> entry = minHeap.top();
            minHeap.pop();
            int cost = entry.first;
            int house = entry.second;
            if(visited.count(house)) continue;
            visited.insert(house);
            result += cost;
            for(auto& n : adjList[house]){
                if(!visited.count(n.second)){
                    minHeap.push(n);
                }    
            }
        }
        return result;
    }
};