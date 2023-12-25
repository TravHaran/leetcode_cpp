#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int count=1;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > prev[1]){ // no overlap
                count++;
                prev = points[i];
            } else {
                prev[1] = min(prev[1], points[i][1]); // update prev end point to account for overlap
            }
        }
        return count;
    }
};