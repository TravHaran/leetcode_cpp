#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int minLen = INT32_MAX;
        int sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                minLen = min(minLen, (r - l) + 1);
                sum -= nums[l];
                l++;
            }
        }
        return minLen==INT32_MAX ? 0 : minLen;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout<<solution.minSubArrayLen(target, nums)<<endl;
}