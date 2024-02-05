#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    // Time: O(V + E), Space: O(V + E), where V represents the number of vertices and E represents the number of edges.
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < prerequisites.size(); i++){ // build adjacency list
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visited;
        unordered_set<int> cycle;
        vector<int> topsort;
        for(int i = 0; i < numCourses; i++){
            // run dfs on every node
            if(!dfs(adjList, i, visited, cycle, topsort)) return {};
        }
        return topsort;
    }

    bool dfs(unordered_map<int, vector<int>>& adj, int course, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& topsort){
        if(cycle.count(course)) return false; // detect cycle
        if(visited.count(course)) return true; // prevent adding visited nodes to topsort
        cycle.insert(course); // add current node to path
        visited.insert(course); // add to visited set
        for(auto neighbor : adj[course]){
            if(!dfs(adj, neighbor, visited, cycle, topsort)) return false;
        }
        topsort.push_back(course); // only after visiting all of the nodes neighbors do we add it to the topsort array
        cycle.erase(course); // after visiting neighbors remove node from path
        return true;
    }
};