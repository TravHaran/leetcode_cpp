#include <vector>
using namespace std;

class Solution {
    // Kadane's algorithm with a twist
    // Time: O(n), Space O(1)
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT32_MIN;
        int minSum = INT32_MAX;
        int curMaxSum = 0;
        int curMinSum = 0;
        int totalSum = 0;
        for(auto n : nums){
            if(curMaxSum < 0) curMaxSum = 0;
            if(curMinSum > 0) curMinSum = 0;
            curMaxSum += n;
            curMinSum += n;
            maxSum = max(maxSum, curMaxSum);
            minSum = min(minSum, curMinSum);
            totalSum += n;
        }
        if(maxSum < 0) return maxSum; // handle edge case where all elements in list are negative
        return max(maxSum, totalSum - minSum);
    }
};