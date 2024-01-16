#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int n = matrix[0].size();
        int r = matrix.size() * n -1;
        int mid;
        int midElement;
        while(l <= r){
            mid = (l+r)/2;
            midElement = matrix[mid / n][mid % n];
            if(midElement==target) return true;
            else if(midElement < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};