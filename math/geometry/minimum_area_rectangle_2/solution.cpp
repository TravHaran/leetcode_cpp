#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution {
    // A rectangle is identified by two diagonals that have the same distance and midpoint
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        double res = INT32_MAX;
        map<pair<double, pair<double, double>>, vector<pair<vector<int>, vector<int>>>> diagCentres;

        vector<int> point1;
        vector<int> point2;
        pair<double, double> mid;
        double d;
        for(int i = 0; i < points.size(); i++){
            point1 = points[i];
            for(int j = i + 1; j < points.size(); j++){
                point2 = points[j];
                mid = midPoint(point1, point2);
                d = dist(point1, point2);
                diagCentres[{d, mid}].push_back({point1, point2});
            }
        }
        pair<vector<int>, vector<int>> pair1;
        pair<vector<int>, vector<int>> pair2;
        double area;
        for(auto [key, val] : diagCentres){
            for(int i = 0; i < val.size(); i++){
                pair1 = val[i];
                for(int j = i+1; j < val.size(); j++){
                    pair2 = val[j];
                    area = dist(pair1.first, pair2.first) * dist(pair1.first, pair2.second);
                    res = min(res, area);
                }
            }
        }
        return res != INT32_MAX ? res : 0;
    }

    pair<double, double> midPoint(vector<int> a, vector<int> b){
        return {(b[0] + a[0]) / 2.0, (b[1] + a[1]) / 2.0};
    }
    
    double dist(vector<int> a, vector<int> b){
        return sqrt((b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]));
    }
};