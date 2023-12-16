#include <vector>
using namespace std;

class Solution {
    /**
     * O(n) Space solution
     * the max water we can trap at any point is the min of max_left and max_right tower values - the height\
     * use two passes to record the max_left and max_right values
     * then use one final pass to compute the total water trapped.
    */
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;

        int water = 0;
        vector<int> max_left = height;
        vector<int> max_right = height;
        
        int max_val = 0;
        for(int i = 0; i < height.size(); i++){
            max_val = max(max_val, height[i]);
            max_left[i] = max_val;
        }

        max_val = 0;
        for(int i = height.size()-1; i >=0; i--){
            max_val = max(max_val, height[i]);
            max_right[i] = max_val;
        }

        for(int i = 0; i < height.size(); i++){
            water += min(max_right[i], max_left[i]) - height[i];
        }
        return water;
    }
};