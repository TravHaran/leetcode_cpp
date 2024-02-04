#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    // Dijkstra's Shortest Path Algorithm: O(E*logV) where E is the number of edges, and V is the number of nodes
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create an adjacency list of the graph
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto& t : times){
            // the source node is t[0]
            // the target node is t[1]; i.e. its neighbor
            // the weight is t[2]
            adjList[t[0]].push_back({t[2], t[1]});
        }
        // dijkstra's algorithm uses a minheap and a visited set
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // minheap stores {weight, target_node}
        minHeap.push({0, k});
        unordered_set<int> visited;
        int result = 0;
        while(!minHeap.empty()){
            pair<int, int> entry = minHeap.top();
            int weight = entry.first;
            int node = entry.second;
            minHeap.pop();

            if(visited.count(entry.second)) continue;

            visited.insert(node);
            result = max(result, weight);
            for(auto n : adjList[node]){
                if(!visited.count(n.second))
                    minHeap.push({weight + n.first, n.second});
            }
        }
        // check if we visited every node
        if(visited.size()==n) return result;
        return -1;  
    }
};
