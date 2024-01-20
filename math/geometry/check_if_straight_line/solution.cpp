#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size(); 
        for(int i = 0 ; i < n; i+=2){
            if(orientation(coordinates[i % n], coordinates[(i+1)%n], coordinates[(i+2)%n])!=0) return false;
        }
        return true;
    }
    int orientation(vector<int> p1, vector<int> p2, vector<int> p3){
        vector<int> v1 = {p2[0]-p1[0], p2[1]-p1[1]};
        vector<int> v2 = {p3[0]-p2[0], p3[1]-p2[1]};
        return v1[0]*v2[1] - v1[1]*v2[0];
    }
};