#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    // Dijkstra's Shortest Path Algorithm: O(E*logV) where E is the number of edges, and V is the number of nodes
    // modified it to use a maxHeap as we need to return the max probability of the path
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // create an adjacency list
        unordered_map<int, vector<pair<double, int>>> adjList;
        for(int i = 0; i < edges.size(); i++){
            // edges[i][0] is the node
            // edges[i][1] is the neighbor
            // succProb[i] is the weight
            adjList[edges[i][0]].push_back({succProb[i], edges[i][1]});
            // the graph is undirected so we add the inverse connection too
            adjList[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1, start_node});
        unordered_set<int> visited;

        while(!maxHeap.empty()){
            pair<double, int> entry = maxHeap.top();
            maxHeap.pop();
            int node = entry.second;
            double weight = entry.first;

            if(node == end_node) return weight;

            if(visited.count(node)) continue;

            visited.insert(node);
            for(auto& n : adjList[node]){
                if(!visited.count(n.second)){
                    maxHeap.push({weight * n.first, n.second});
                }
            }
        }
        return 0;
    }
};