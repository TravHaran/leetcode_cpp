#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end()); // sorting gives us the valid arrangement of points for a square
        // check if edge case where 2 points are the same, all points must be distinct in a square
        for(int i = 0; i < 3; i++){
            if(points[i]==points[i+1]) return false;
        }
        if(dist(points[0], points[1]) != dist(points[2], points[3])) return false; // equality of horizontal sides
        if(dist(points[0], points[2]) != dist(points[1], points[3])) return false; // equality of vertical sides
        if(dist(points[0], points[3]) != dist(points[1], points[2])) return false; // equality of diagonal sides 
        if(dist(points[0], points[1]) != dist(points[0], points[2])) return false; // make sure horizontal = vertical
        return true;
    }

    double dist(vector<int> a, vector<int> b){
        // compute euclidiean distance between two points
        return sqrt((b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]));
    }
};