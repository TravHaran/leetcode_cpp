#include <vector>
using namespace std;

class Solution {
    // using the cross product we can tell where a corner is facing inward or outward
    // if cross product is > 0 then it is counterclockwise (inward)
    // if cross product is < 0 then it is clockwise (outward)
    // a polygon is convex if all the corners are facing the same direction
    // For any triplet of ordered points in a convex polygon, their orientation should remain the same : counterclockwise, clockwise, or colinear.
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int prev = -2; // dummy prev value
        for(int i = 0; i < n; i++) {
            int orientation = getOrientation(points[i % n], points[(i+1) % n], points[(i+2) % n]);
            // handle case were triplet is colinear
            if(orientation == 0) continue;
            if(prev == -2 || orientation == prev){
                prev = orientation;
            } else {
                return false;
            }
        }
        return true;
    }

    int getOrientation(vector<int> p1, vector<int> p2, vector<int> p3){
        // cross product of three vectors
        vector<int> v1 = {p2[0] - p1[0], p2[1] - p1[1]};
        vector<int> v2 = {p3[0] - p2[0], p3[1] - p2[1]};
        int crossProd = v1[0] * v2[1] - v1[1] * v2[0];
        if(crossProd < 0) return -1; // clockwise
        if(crossProd > 0) return 1; // counterclockwise
        return 0; // colinear
    }
};