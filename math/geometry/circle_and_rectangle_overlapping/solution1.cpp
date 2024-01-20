#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                if(distance(x, y, xCenter, yCenter) <= radius) return true;
            }
        }
        return false;
    }

    double distance(int x1, int y1, int x2, int y2){
        return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    }
};