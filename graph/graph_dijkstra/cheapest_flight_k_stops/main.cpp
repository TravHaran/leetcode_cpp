#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    // Dijkstra's Algorithm with modification
    // Time: O(N + E*K log(E*K)), where E is the number of flights, and N is the number of cities
    // Space: O(N + E*K)
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create an adjacenecy list
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto& flight : flights){
            // flight[0] node
            // flight[1] neighbor
            // flight[2] weight
            adjList[flight[0]].push_back({flight[2], flight[1]});
        }
        //create a list to store the number of stops from src to each node
        // initialize each value to be large indicating that we haven't visited the node
        vector<int> stops(n);
        fill(stops.begin(), stops.end(), INT32_MAX);

        //create minHeap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, src, 0});

        while(!minHeap.empty()){
            vector<int> entry = minHeap.top();
            minHeap.pop();
            int dist = entry[0];
            int node = entry[1];
            int steps = entry[2];
            // check if we already visited this node earlier with fewer steps, or if we've surpassed k+1 steps
            // if which case we skip 
            if(steps > k+1 || steps > stops[node]) continue;
            if(node == dst) return dist;
            stops[node] = steps; // update the number of steps taken to visit the node
            for(auto& n : adjList[node]){
                minHeap.push({dist + n.first, n.second, steps+1});
            }
        }
        return -1;  
    }
};