#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        vector<int> dist(n);
        dist[0] = 0;
        for(int i = 1; i < n; i++){
            dist[i] = maxMoves + 1;
        }
        map<pair<int,int>, int> used;
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 0});
        while(!minHeap.empty()){
            pair<int, int> entry = minHeap.top();
            minHeap.pop();
            int d = entry.first;
            int node = entry.second;
            if(d > dist[node]) continue;
            ans++;
            for(auto& pair : adjList[node]){
                // maxMoves - d is how much further we can walk from this node
                // weight is how many new nodes  there are on this edge
                int nei = pair.first;
                int weight = pair.second;
                used[{node, nei}] = min(weight, maxMoves-d);

                //d2 is the total distance to reach nei in the original graph
                int d2 = d + weight + 1;
                if(d2 < dist[nei]){
                    minHeap.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }
        // at the end, each edge (u, v, w) can be used with a min of w new nodes, used[u, v] nodes and used[v, u] nodes (both sides)
        for(auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            ans += min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};