#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

class Solution {
    /*This method only works for integer/rational coordinates*/
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_set<double> distances;
        // go through all combinations of points
        for(int i = 0; i < 3; i++){
            for(int j = i+1; j < 4; j++){
                if(points[i]==points[j]) return false; // a valid sqaure must have distinct points
                distances.insert(dist(points[i], points[j]));
            }
        }
        // a valid square can only have 2 distinct distances (side length & diagonal length)
        return distances.size()==2;
    }

    double dist(vector<int> a, vector<int> b){
        // compute euclidiean distance between two points
        return sqrt((b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]));
    }
};