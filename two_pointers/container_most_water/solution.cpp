#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_water = INT32_MIN;
        while(l < r){
            max_water = max(max_water, min(height[l], height[r]) * (r-l));
            if(height[l]<height[r]){ // if left height is less than right height we may get a higher max if we increment left
                l++;
            } else { // if right height is less than left height we may get a higher max if we decrement right
                r--;
            }
        }
        return max_water;
        
    }
};