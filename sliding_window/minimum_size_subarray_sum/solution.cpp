#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT32_MAX;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                min_len = min(min_len, (r - l)+1);
                sum -= nums[l];
                l++;
            }
        }
        if (min_len==INT32_MAX)
            return 0;
        return min_len==INT32_MAX ? 0: min_len;
        
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout<<solution.minSubArrayLen(target, nums)<<endl;
}