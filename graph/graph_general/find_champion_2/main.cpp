#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // indegree count
        vector<int> indegree(n);
        for(auto& e: edges){
            indegree[e[1]]++;
        }
        int result;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                result = i;
                count++;
                if(count > 1) break;
            } 
        }
        if(count==1) return result;
        return -1;
    }
};