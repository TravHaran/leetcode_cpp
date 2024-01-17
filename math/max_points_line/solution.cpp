#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // for each point determine if it lies on the longest line
        // count all points with the same slope
        // update result with max
        int res = 1;
        unordered_map<double, int> slopeMap;
        double slope;
        for(int i = 0; i < points.size(); i++){
            vector<int> p1 = points[i];
            slopeMap = {};
            for(int j = 0; j < points.size(); j++){
                if(i==j) continue;
                vector<int> p2 = points[j];
                if(p2[0]==p1[0]) slope = INT32_MAX;
                else slope = (double)(p2[1]-p1[1])/(p2[0]-p1[0]);
                slopeMap[slope]++;
                res = max(res, slopeMap[slope]+1);
            }
        }
        return res;
    }
};