#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool compareOrigin(vector<int>& a, vector<int>& b){
        double distA = dist(a, {0,0});
        double distB = dist(b, {0,0});
        return distA < distB;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [this](vector<int>& a, vector<int>& b){
            return compareOrigin(a, b);
        });
        return {points.begin(), points.begin()+k};
    }
    
    double dist(vector<int> a, vector<int> b){
        return sqrt((b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]));
    }
};