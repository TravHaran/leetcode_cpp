#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minDistHeap;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                double d = abs(r - rCenter) + abs(c - cCenter); // euclidean distance in 1d
                minDistHeap.push({d, {r, c}});
            }
        }
        vector<vector<int>> res;
        while(!minDistHeap.empty()){
            pair<int, int> point = minDistHeap.top().second;
            res.push_back({point.first, point.second});
            minDistHeap.pop();
        }
        return res;
    }
};