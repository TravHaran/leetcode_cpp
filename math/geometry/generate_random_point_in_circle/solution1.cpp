#include <vector>
using namespace std;

class Solution {
    // Rejection Sampling
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
        double x;
        double y;
        while(true){
            //generate random coordinate within square bounds
            // double r = (rand() / ( double )RAND_MAX) * (upper - lower) + lower
            x = (rand() / ( double )RAND_MAX) * ((_x_c+_r) - (_x_c-_r)) + _x_c-_r;
            y = (rand() / ( double )RAND_MAX) * ((_y_c+_r) - (_y_c-_r)) + _y_c-_r;
            //check if coordinates are within circle bounds
            // use pythogorean theorem to check if the distance from the point to the center is less than the radius
            if(((x-_x_c)*(x-_x_c) + (y-_y_c)*(y-_y_c)) <= _r*_r) return {x, y};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */