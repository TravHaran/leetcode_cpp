#include <vector>
#include <unordered_map>
#include <string>
#include <deque>
#include <unordered_set>

using namespace std;

class Solution {
    // Time: O(M*N); for each query we need to traverse the graph which in worst case could take O(N) time, building out the graph also takes O(N) time/
    // Space: O(N); in worst case there is no overlap among the equations in which case we'd have N nodes and 2N edges in the graph which makes space of the graph O(N+2N) = O(3N) = O(N)
    // queue in the bfs traversal can take up O(N) space and the visited set can also take up O(N) space making the total space O(N+N+N) = O(3N) = O(N)
    // if we count the output result vector into space complexity, then it is O(N+M);
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct weighted graph mapping the numerator variable in the equations as nodes and the neighbors as the denominators with the result as the weight
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); i++){
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            graph[numerator].push_back({denominator, values[i]});
            // also map the denominator to the numerator storing the inverse as the result
            graph[denominator].push_back({numerator, 1/values[i]}); 
        }
        // for each query traverse the graph and multiply the weights to get our answer
        vector<double> result;
        for(int i = 0; i < queries.size(); i++){
            string numerator = queries[i][0];
            string denominator = queries[i][1];
            double answer = bfs(graph, numerator, denominator);
            result.push_back(answer);
        } 
        return result;
    }

    // bfs graph traversal
    double bfs(unordered_map<string, vector<pair<string, double>>> graph, string numerator, string denominator){
        if(!graph.count(numerator) || !graph.count(denominator)) return -1;
        deque<pair<string, double>> q {{numerator, 1}};
        unordered_set<string> visited {numerator}; // use a set to make sure that we don't traverse in a cycle
        //start at numerator and traverse until you find denominator
        string node;
        string neighbor;
        double curWeight;
        while(!q.empty()){
            node = q.front().first;
            curWeight = q.front().second;
            if(node==denominator) return curWeight;
            q.pop_front();
            for(auto el : graph[node]){
                neighbor = el.first;
                if(!visited.count(neighbor)){
                    //multiply the weight as we traverse
                    q.push_back({neighbor, el.second*curWeight}); 
                    visited.insert(neighbor);
                }  
            }
        }
        return -1;
    }
};