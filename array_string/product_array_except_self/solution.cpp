#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<2)
            return nums;
        // two passes to compute pefix and postfix
        int pre = 1;
        int post = 1;
        vector<int> result = nums;
        for(int i = 1; i <= nums.size(); i++){
            result[i-1] = pre;
            pre *= nums[i-1];
        }
        for(int j = nums.size()-2; j >=-1; j--){
            result[j+1] *= post;
            post *= nums[j+1];
        }
        return result;
    }
};