#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // find the nearest x coordinate to the circle
        int x = max(x1, min(xCenter, x2));
        // find the nearest y coordinate to the circle;
        int y = max(y1, min(yCenter, y2));
        if(distance(x, y, xCenter, yCenter) <= radius) return true;
        return false;
    }

    double distance(int x1, int y1, int x2, int y2){
        return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    }
};