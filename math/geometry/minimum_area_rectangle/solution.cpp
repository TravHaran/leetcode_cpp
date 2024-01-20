#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT32_MAX;
        set<pair<int, int>> visited;
        for(auto point1 : points){
            int x1 = point1[0];
            int y1 = point1[1];
            for(auto point2 : visited){
                int x2 = point2.first;
                int y2 = point2.second;
                // check if a rectangle is formed from coordinates of point 1 and point2
                if(visited.count({x1, y2}) && visited.count({x2, y1})){
                    int area = abs(x2-x1) * abs(y2-y1);
                    res = min(res, area);
                }
            }
            visited.insert({x1, y1});
        }
        return res != INT32_MAX ? res : 0;
    }
};