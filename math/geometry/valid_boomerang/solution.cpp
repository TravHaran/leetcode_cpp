#include <vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return orientation(points[0], points[1], points[2]);
        
    }
    int orientation(vector<int>p1, vector<int> p2, vector<int> p3){
        vector<int> v1 = {p2[0]-p1[0], p2[1]-p1[1]};
        vector<int> v2 = {p3[0]-p2[0], p3[1]-p2[1]};
        int cross = v1[0]*v2[1] - v1[1]*v2[0];
        // if cross product is zero the lines are colinear
        return !cross==0;
    }
};