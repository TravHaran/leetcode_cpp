#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = INT32_MIN;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                for(int k = 0; k < points.size(); k++){
                    area = max(area, shoelaceFormula(points[i], points[j], points[k]));
                }
            }
        }
        return area;
    }

    double shoelaceFormula(vector<int> p1, vector<int> p2, vector<int> p3){
        return 0.5 * (p1[0] * (p2[1]-p3[1]) + p2[0] * (p3[1]-p1[1]) + p3[0] * (p1[1] - p2[1]));
    }
};