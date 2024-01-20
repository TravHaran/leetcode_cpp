#include <vector>
#include <math.h>
#include <queue>

using namespace std;

class Solution {
    /**
     * store the distance_to_origin and the corresponding point in a minHeap
     * pop from the heap k times and append to the result 
    */
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<>> minDistHeap;
        vector<vector<int>> res;
        double distToOrigin;
        for(auto point : points){
            distToOrigin = dist(point, {0, 0});
            minDistHeap.push({distToOrigin, point});
        }
        pair<double, vector<int>> minDistPair;
        while(k > 0 && !minDistHeap.empty()){
            minDistPair = minDistHeap.top();
            minDistHeap.pop();
            res.push_back(minDistPair.second);
            k--;
        }
        return res;
    }
    
    double dist(vector<int> a, vector<int> b){
        return sqrt((b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]));
    }
};