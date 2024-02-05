#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    // Prim's Algorithm (Minimum Spanning Tree)
    // Time: O(V + E*log(V))
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        //create an adjacency list
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto& c : connections){
            // c[0] is the node
            // c[1] is the neighbor
            // c[2] is the weight
            adjList[c[0]].push_back({c[2], c[1]});
            // bidirectional connection
            adjList[c[1]].push_back({c[2], c[0]});
        }
        int result = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 1});
        unordered_set<int> visited;
        while(!minHeap.empty()){
            pair<int, int> entry = minHeap.top();
            minHeap.pop();
            int cost = entry.first;
            int city = entry.second;
            if(visited.count(city)) continue;
            visited.insert(city);
            result += cost;
            for(auto& n : adjList[city]){
                if(!visited.count(n.second))
                    minHeap.push(n);
            }
        }
        visited.size() != n ? result = -1 : result;
        return result;
        
    }
};