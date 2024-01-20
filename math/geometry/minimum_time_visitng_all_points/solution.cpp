#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i =0; i < points.size()-1; i++){
            int xdist = abs(points[i+1][0]-points[i][0]);
            int ydist = abs(points[i+1][1]-points[i][1]);
            if(xdist==ydist){
                // this means we can move diagonally
                // the time taken is euqal to eight xdist or ydist
                res += xdist;
            } else { 
                // we can move either horizontally or vertically
                res += max(xdist, ydist);
            }
        }
        return res;
    }
};