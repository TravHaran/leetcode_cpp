#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        //find upper bound target
        int l = 0; 
        int r = nums.size()-1;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid]==target){
                result[1] = mid;
                l = mid+1;
            } else if(nums[mid] < target){
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }

        //find lower bound target
        l = 0; 
        r = nums.size()-1;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid]==target){
                result[0] = mid;
                r = mid-1;
            } else if(nums[mid] < target){
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }
        return result; 
    }
};