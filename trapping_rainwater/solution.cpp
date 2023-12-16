#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
    /**
     * the water trapped by any tower depends on the minimum of maximum height of towers on both sides.
     * we search from both the left and right end by maintaining two pointers left and right separately. 
     * If there is a larger tower at the right end, then the water trapped would be dependant on the tower’s height in the direction from left to right. 
     * Similarly, if the tower at the right end is smaller, then the water trapped would be dependant on the tower’s height in the direction from right to left.
    */
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int water = 0;
        int left = 0;
        int right = height.size()-1;
        int max_right = height[right];
        int max_left = height[left];

        while(left < right){
            if(max_left < max_right){
                left++;
                max_left = max(max_left, height[left]);
                water += max_left - height[left];

            } else {
                right--;
                max_right = max(max_right, height[right]);
                water += max_right - height[right];
            }
            
        }
        return water;
    }
};

int main(){
    Solution solution;
    // {4,2,0,3,2,5}, expect 9
    // {0,1,0,2,1,0,1,3,2,1,2,1} expect 6
    vector<int> height = {4,2,3};
    cout<<"answer: "<<solution.trap(height)<<endl;
    // assert(solution.trap(height)==6);
}