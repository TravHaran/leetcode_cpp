#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // compute the areas of the two reactangles;
        int rec1 = (ax2-ax1) * (ay2-ay1);
        int rec2 = (bx2-bx1) * (by2-by1);

        int overlap = 0;
        // compute overlap area
        int hOverlap = min(ax2, bx2) - max(ax1, bx1);
        int vOverlap = min(ay2, by2) - max(ay1, by1);
        // check if overlap exists
        if(vOverlap>0 && hOverlap>0) overlap = vOverlap * hOverlap;
        return rec1 + rec2 - overlap;
        
    }
};