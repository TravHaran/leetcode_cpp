#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> biGraph(n, vector<int>());
        for(auto& c : connections){
            biGraph[c[0]].push_back(c[1]);
            biGraph[c[1]].push_back(c[0]);
        }

        vector<vector<int>> graph(n, vector<int>());
        for(auto& c : connections){
            graph[c[0]].push_back(c[1]);
        }

        queue<int> q({0});
        unordered_set<int> visit;
        int rev_count=0;
        while(!q.empty()){
            int city = q.front();
            q.pop();
            visit.insert(city);
            for(auto& nei_city : biGraph[city]){
                if(!visit.count(nei_city)){
                    q.push(nei_city);
                    bool found_connection = false;
                    for(auto& n : graph[nei_city]){
                        if(n == city){
                            found_connection = true;
                            break;
                        }
                    }
                    if(!found_connection) rev_count++;
                }   
            }
        }
        return rev_count;
    }
};