#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0; // handle edge case
        int l = 0;
        int r = nums.size();
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(mid == 0 || mid == nums.size()-1){ // handle edge case
                if(mid==0 && nums[mid] < nums[mid+1]){
                    l = mid+1;
                    continue;
                }
                if(mid==nums.size()-1 && nums[mid] < nums[mid-1]){
                    r = mid -1;
                    continue;
                }
                return mid;
            }
            //binary search
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
            else if(nums[mid] < nums[mid+1]){
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        return mid;
    }
};