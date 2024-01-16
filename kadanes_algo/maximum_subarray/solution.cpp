#include <vector>
using namespace std;

class Solution {
    // Kadane's algorithm
    // Time: O(n), Space O(1)
public:
    int maxSubArray(vector<int>& nums){
        int maxSum = INT32_MIN;
        int curSum = 0;
        for(auto n : nums){
            if(curSum < 0) curSum = 0;
            curSum += n;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};