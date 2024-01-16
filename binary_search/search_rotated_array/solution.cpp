#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid] >= nums[l]){//left half is sorted
                //check if target could be in left half
                if(target >= nums[l] && target < nums[mid]) r = mid-1;
                else l = mid + 1;
            } else {//right half is sorted
                //check if target could be in right half
                if(target <= nums[r] && target > nums[mid]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};