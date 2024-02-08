#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    /**
     * Dijkstra w/ modifications
     * we'll need 4 modifications
     * 1. Construct 2 graphs one for redEdges and one for blueEdges
     * 2. Keep track of 2 possible shortest distances to each node arrived from either red or blue edges
     * 3. Store the clors of the previous edge along with the current distance and node
     * 4. Pick neighbors via red & blue edges alternatively and update the respective colors shortest distance
     * The answer will be the min distance between the red shortest and blue shortest,
     * if it's unreachable it will be -1.
    */
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //construct 2 graphs one for redEdges and one for blueEdges
        unordered_map<int, vector<int>> rGraph;
        for(auto& edge : redEdges){
            rGraph[edge[0]].push_back(edge[1]);
        }
        unordered_map<int, vector<int>> bGraph;
        for(auto& edge : blueEdges){
            bGraph[edge[0]].push_back(edge[1]);
        }
        // in the pq we will store cost, node, and previous color
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, greater<>> minHeap;
        minHeap.push({0, 0, 'r'});
        minHeap.push({0, 0, 'b'});
        vector<int> rShortest(n, INT32_MAX);
        vector<int> bShortest(n, INT32_MAX);
        vector<int> neighbors;
        char nextColor;
        vector<int>* shortest;
        while(!minHeap.empty()){
            tuple<int, int, char> entry = minHeap.top();
            minHeap.pop();
            int dist = get<0>(entry);
            int node = get<1>(entry);
            char prevColor = get<2>(entry);
            
            if(prevColor == 'r'){
                shortest = &bShortest;
                neighbors = bGraph[node];
                nextColor = 'b';

            } else {
                shortest = &rShortest;
                neighbors = rGraph[node];
                nextColor = 'r';
            }
            for(auto& n : neighbors){
                if(dist + 1 < shortest->at(n)){
                    shortest->at(n) = dist + 1;
                    minHeap.push({dist + 1, n, nextColor});
                }
            }
        }
        vector<int> ans(n);
        ans[0] = 0;
        int val;
        for(int i = 1; i < n; i++){
            min(rShortest[i], bShortest[i]) == INT32_MAX ? val = -1 : val = min(rShortest[i], bShortest[i]);
            ans[i] = val;
        }
        return ans;
    }
};