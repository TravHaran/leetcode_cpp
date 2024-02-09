#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create adjacency list
        vector<vector<pair<int, int>>> adjList(n);
        for(auto& edge : edges){
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }
        // for each city we'll apply dijkstras and update distances
        int minDist = INT32_MAX;
        int result = 0;
        for(int city = 0; city < n; city++){
            int distance = dijkstra(n, edges, distanceThreshold, city, adjList);
            minDist = min(minDist, distance);
            if(distance == minDist) result = city;
        }
        return result;

    }

    int dijkstra(int n, vector<vector<int>>& edges, int distanceThreshold, int city, vector<vector<pair<int, int>>>& adjList){
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> visit(n, 0);
        dist[city] = 0;
        minHeap.push({0, city});
        while(!minHeap.empty()){
            pair<int, int> entry = minHeap.top();
            minHeap.pop();
            int d = entry.first;
            int cur_city = entry.second;
            if(visit[cur_city]) continue;
            visit[cur_city] = 1;
            for(auto& nei : adjList[cur_city]){
                int nei_city = nei.first;
                int nei_dist = nei.second;
                if(dist[nei_city] > d + nei_dist)
                    dist[nei_city] = d + nei_dist;
                    minHeap.push({dist[nei_city], nei_city});
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i != city && dist[i] <= distanceThreshold){
                cnt++;
            }
        }
        return cnt;
    }
};