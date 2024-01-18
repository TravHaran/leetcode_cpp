#include <vector>
#include <math.h>
using namespace std;

class Solution {
    // Polar Coordinates + Inverse Transform Sampling
public:
    double _r;
    double _x_c;
    double _y_c;
    Solution(double radius, double x_center, double y_center) {
        _r = radius;
        _x_c = x_center;
        _y_c = y_center;
    }
    
    vector<double> randPoint() {
        // get random polar coordinates
        // Inverse Transform Sample: sqrt makes uniform distribution, because the area of circle depends on radius^2
        double r = sqrt(rand() / (double)RAND_MAX) * (_r);
        double theta = (rand() / (double)RAND_MAX) * (2*M_PI);
        // convert to cartesion coordinates
        return {_x_c + r*cos(theta), _y_c + r*sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */