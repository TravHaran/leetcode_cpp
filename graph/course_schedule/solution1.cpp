#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        // construct adj list graph out of prerequisites
        unordered_map<int, vector<int>> courseGraph;
        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            if(course==prereq) return false;
            courseGraph[course].push_back(prereq);
        }
        unordered_set<int> visited;
        // run dfs for each course
        for(int i = 0; i < numCourses; i++){
            if(!dfs(courseGraph, i, visited)) return false;
        }
        return true;
    }
    bool dfs(unordered_map<int, vector<int>>& adjList, int course, unordered_set<int>& visited){
        if(visited.count(course)) return false; // cycle detected
        if(adjList[course].empty()) return true; // no prerequisites returns true
        visited.insert(course);
        for(auto neighbor : adjList[course]){ // recursively check neighbors
           if(!dfs(adjList, neighbor, visited)) return false;
        }
        //backtrack
        visited.erase(course);
        adjList[course] = {};
        return true;
    }
};